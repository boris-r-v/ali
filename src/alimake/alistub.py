#!/usr/bin/python
# coding=UTF-8

# -*- coding : UTF-8 -*-


import xml.dom
from xml.dom.minidom import parse
import re,  os
from string import *
from attrTemp import *

class ModuleNotFoundError(Exception):
    """ Исключение 'Модуль не найден' """
    pass

class AttributeNotFoundError(Exception):
    """ Исключение 'Атрибут не найден' """
    pass

class AttributeDuplicationError(Exception):
    """ Исключение 'Дублирующийся атрибут'. """
    pass


class AliStubCreator:


    doc=""
    dom=""

    def __init__(self, path2file, path2inc="/usr/include/ali/idl"):
        self.path2inc = path2inc
        self.path2file = path2file
        dom = parse (path2file)
        self.createObjectsStub( dom )

#Главный метод сознадния заглушки    
    def createObjectsStub(self, dom ):
        path2lib = "/usr/lib/ali/bend"
        ItemName = ""
        ItemModul = ""
        items = dom.getElementsByTagName("obj")
        for item in items:
            ItemName  = item.getAttribute("name")
            ItemModul = item.getAttribute("ns")
            attributes = self.extractAttributes(item)
            # Помещаем атрибуты в словарь для удаления повторов
            attrDict = {}
            for attr in attributes:
                attrDict[attr.getAttribute("name")] = attr
            # Добавляем к элементу
            for attr in attrDict.values():
                item.appendChild(attr)
        #Header
        content_fname = ItemName+".h"
        if (os.path.exists(content_fname) == 0):
            f1=open(path2lib+"/stubs/Stub.h")
            tmp=f1.read()
            f1.close()
            tmp = re.sub("@ITEM@", ItemName, tmp, 100 )
            content = re.sub("@MODUL@", ItemModul, tmp, 100 )
            
            open(content_fname, 'w').write(content)

        #Footer
        content_fname = ItemName+".cpp"
        if (os.path.exists(content_fname) == 0):    
            f1=open(path2lib+"/stubs/Stub.cpp")
            tmp=f1.read()
            f1.close()
            tmp = re.sub("@ITEM@", ItemName, tmp, 100 )
            content = re.sub("@MODUL@", ItemModul, tmp, 100 )
            open(content_fname, 'w').write(content)


        #HeaderFactory
        content_fname = ItemName+"Factory.hh"
        if (os.path.exists(content_fname) == 0):    
            f1=open(path2lib+"/stubs/StubFactory.hh.tmpl")
            tmp=f1.read()
            f1.close()
            tmp = re.sub("@ITEM@", ItemName, tmp, 100 )
            content = re.sub("@MODUL@", ItemModul, tmp, 100 )
            open(content_fname, 'w').write(content)

        #FooterFactory
        content_fname = ItemName+"Factory.cc"
        if (os.path.exists(content_fname) == 0):    
            f1=open(path2lib+"/stubs/StubFactory.cc.tmpl")
            tmp=f1.read()
            f1.close()
            tmp = re.sub("@ITEM@", ItemName, tmp, 100 )
            content = re.sub("@MODUL@", ItemModul, tmp, 100 )
            open(content_fname, 'w').write(content)

        #Makefile
        if (os.path.exists("Makefile") == 0):    
            f1=open(path2lib+"/stubs/Makefile")
            tmp=f1.read()
            f1.close()
            tmp = re.sub("@ITEM@", ItemName, tmp, 100 )
            content = re.sub("@MODUL@", ItemModul, tmp, 100 )
            open ("Makefile", 'w').write(content)
    
        #Create ItemBase Header
        content_fname = ItemName+"Base.hh"
        f1=open(path2lib+"/stubs/StubBase_1.hh.tmpl")
        tmp=f1.read()
        f1.close()
        tmp = re.sub("@ITEM@", ItemName, tmp, 100 )
        content = re.sub("@MODUL@", ItemModul, tmp, 100 )
        content = content + self.createAttr_hh( dom )
        f1=open(path2lib+"/stubs/StubBase_2.hh.tmpl")
        tmp = f1.read()
        f1.close()
        tmp = re.sub("@ITEM@", ItemName, tmp, 100 )
        tmp = re.sub("@MODUL@", ItemModul, tmp, 100 )
        content = content + tmp
        open(content_fname, 'w').write(content)

        #Create ItemBase Footer
        content_fname = ItemName+"Base.cc"
        f1=open(path2lib+"/stubs/StubBase_1.cc.tmpl")
        tmp=f1.read()
        f1.close()
        tmp = re.sub("@ITEM@", ItemName, tmp, 100 )
        tmp = re.sub("@MODUL@", ItemModul, tmp, 100 )
        content = tmp + self.createInitVal( dom )
        f2=open(path2lib+"/stubs/StubBase_2.cc.tmpl")
        tmp = f2.read()
        f2.close()
        tmp = re.sub("@ITEM@", ItemName, tmp, 100 )
        tmp = re.sub("@MODUL@", ItemModul, tmp, 100 )
        content = content + tmp
        content = content + self.createAttrsMethod( dom, ItemName, ItemModul )        
        content = content + self.createHasAttr( dom, ItemName, ItemModul )        
        content = content + self.createSetAttr( dom, ItemName, ItemModul )        
        content = content + self.createGetAttr( dom, ItemName, ItemModul )        
        open(content_fname, 'w').write(content)
        #print "Created Stub for object repo:",ItemModul,"/",ItemName,".1.0"

#Создает начальные нулевые значения для всех аттрибутов
    def createInitVal(self, dom ):
        attrs=dom.getElementsByTagName("attribute")
        cont = ""
        for obj in attrs:
            attrName = obj.getAttribute("name")
            attrType =  obj.getAttribute("type")
            attrDefault =  obj.getAttribute("default")
            if ( 0 == len( attrDefault ) ):
                attrDefault  = "0"
                
            if (attrType == "double"  ):
                cont = cont + "    "+attrName+"_ = "+attrDefault+";"+'\n'
            if (attrType == "float"  ): 
                cont = cont +  "   "+attrName+"_ = "+attrDefault+";"+'\n'
            if (attrType == "int" ):
                cont = cont + "    "+attrName+"_ = "+attrDefault+";"+'\n'                
            if (attrType == "long" ):
                cont = cont +  "   "+attrName+"_ = "+attrDefault+";"+'\n'
            if (attrType == "bool" ):
                cont = cont +  "   "+attrName+"_ = "+attrDefault+";"+'\n'
        return cont

#Создает метод getAttr__(...) из ItemBase.cc
    def createGetAttr(self, dom, ItemName, ItemModul ):
        cont = re.sub("@ITEM@", ItemName, getAttr_1, 100 )
        cont = re.sub("@MODUL@", ItemModul, cont, 100 )
        attrs=dom.getElementsByTagName("attribute")
        for obj in attrs:
            attrName = obj.getAttribute("name")
            attrType =  obj.getAttribute("type")
            if (attrType == "string" ):
                tmp = re.sub("@NAME@", attrName, getAttrString, 100 )
                cont =  cont + tmp
            if (attrType == "double"  ):
                tmp = re.sub("@NAME@", attrName, getAttrDouble, 100 )
                cont =  cont + tmp
            if (attrType == "float"  ):
                tmp = re.sub("@NAME@", attrName, getAttrDouble, 100 )
                cont =  cont + tmp
            if (attrType == "int" ):
                tmp = re.sub("@NAME@", attrName, getAttrInt, 100 )
                cont =  cont + tmp
            if (attrType == "long" ):
                tmp = re.sub("@NAME@", attrName, getAttrLong, 100 )
                cont =  cont + tmp
            if (attrType == "bool" ):
                tmp = re.sub("@NAME@", attrName, getAttrBool, 100 )
                cont =  cont + tmp
        cont += getAttr_2
        return cont

#Создает метод setAttr__(...) из ItemBase.cc
    def createSetAttr(self, dom, ItemName, ItemModul ):
        cont = re.sub("@ITEM@", ItemName, setAttr_1, 100 )
        cont = re.sub("@MODUL@", ItemModul, cont, 100 )
        attrs=dom.getElementsByTagName("attribute")
        for obj in attrs:
            attrName = obj.getAttribute("name")
            attrType =  obj.getAttribute("type")
            if (attrType == "string" ):
                tmp = re.sub("@NAME@", attrName, setAttrString, 100 )
                cont =  cont + tmp
            if (attrType == "double"  ):
                tmp = re.sub("@NAME@", attrName, setAttrDouble, 100 )
                cont =  cont + tmp
            if (attrType == "float"  ):
                tmp = re.sub("@NAME@", attrName, setAttrDouble, 100 )
                cont =  cont + tmp
            if (attrType == "int" ):
                tmp = re.sub("@NAME@", attrName, setAttrInt, 100 )
                cont =  cont + tmp
            if (attrType == "long" ):
                tmp = re.sub("@NAME@", attrName, setAttrLong, 100 )
                cont =  cont + tmp
            if (attrType == "bool" ):
                tmp = re.sub("@NAME@", attrName, setAttrBool, 100 )
                cont =  cont + tmp
        cont += setAttr_2
        return cont

#Создает метод hasIdlAttr__(...) из ItemBase.cc
    def createHasAttr(self, dom, ItemName, ItemModul ):
        cont = re.sub("@ITEM@", ItemName, checkAttr_1, 100 )
        cont = re.sub("@MODUL@", ItemModul, cont, 100 )
        attrs = dom.getElementsByTagName("attribute")
        for obj in attrs:
            attrName = obj.getAttribute("name")
            tmp = re.sub("@NAME@", attrName, checkAttr_2, 100 )
            cont =  cont + tmp
        cont += checkAttr_3
        return cont

#Создает сеттеры и геттеры для аттрибутов объекта
    def createAttrsMethod(self, dom, ItemName, ItemModul ):
        cont=""
        attrs=dom.getElementsByTagName("attribute")
        for obj in attrs:
            attrName = obj.getAttribute("name")
            attrType =  obj.getAttribute("type")
            if (attrType == "string" ):
                attrType = "std::string"
            tmp = re.sub("@NAME@", attrName, methodStub, 100 )
            tmp = re.sub("@TYPE@", attrType, tmp, 100 )
            tmp = re.sub("@ITEM@", ItemName, tmp, 100 )
            tmp = re.sub("@MODUL@", ItemModul, tmp, 100 )
            cont = cont + tmp
            if (attrType == "std::string" ):
                tmp = re.sub("@NAME@", attrName, methodStubString, 100 )
                cont =  cont + tmp
            if (attrType == "double"  ):
                tmp = re.sub("@NAME@", attrName, methodStubDouble, 100 )
                cont =  cont + tmp
            if (attrType == "float"  ):
                tmp = re.sub("@NAME@", attrName, methodStubDouble, 100 )
                cont =  cont + tmp
            if (attrType == "int" ):
                tmp = re.sub("@NAME@", attrName, methodStubInt, 100 )
                cont =  cont + tmp
            if (attrType == "long" ):
                tmp = re.sub("@NAME@", attrName, methodStubLong, 100 )
                cont =  cont + tmp
            if (attrType == "bool" ):
                tmp = re.sub("@NAME@", attrName, methodStubBool, 100 )
                cont =  cont + tmp
        return cont

#Создает заголовочный файл ItemBase.hh        
    def createAttr_hh(self, dom ):
        content = ""
        attrs=dom.getElementsByTagName("attribute")
        once = 0
        for obj in attrs:
            if (once == 0 ):
                content = content + methodAccessSpec        
                once = 1
            attrName = obj.getAttribute("name")
            attrType =  obj.getAttribute("type")
            if (attrType == "string" ):
                attrType = "std::string"
            tmp = re.sub("@NAME@", attrName, methodDef, 100 )
            tmp = re.sub("@TYPE@", attrType, tmp, 100 )
            content = content + tmp
        attrs=dom.getElementsByTagName("attribute")
        once = 0
        for obj in attrs:
            if (once == 0 ):
                content = content + attrAccessSpec        
                once = 1
            attrName = obj.getAttribute("name")
            attrType =  obj.getAttribute("type")
            if (attrType == "string" ):
                attrType = "std::string"
            tmp = re.sub("@NAME@", attrName, attrDef, 100 )
            tmp = re.sub("@TYPE@", attrType, tmp, 100 )
            content = content + tmp
        return content

    def extractAttributes(self,root):
        """ Выдирает нужные атрибурты """
        inherites = parseInherites(
            root.getAttribute("inheritance")
        )
        default_ns = root.getAttribute("ns")
        attributes = []
        for (nspace, mname, attrs) in inherites:
            nspace = nspace or default_ns
            try:
                inheritee   = parse("%s/%s/%s.xml" % (self.path2inc, nspace, mname))
                attributes += self.filterAttributes(inheritee, nspace, mname, attrs)
            except (IOError,IndexError,ModuleNotFoundError):
                print ( "ERROR: Can not find module %s:%s " % (nspace, mname) )
                continue
        return attributes

    def filterAttributes(self, dom, nspace, objname, attrnames):
        found = None
        objects = dom.getElementsByTagName("obj")
        for obj in objects:
            if      obj.getAttribute("name")  == objname \
                and obj.getAttribute("ns") == nspace:
                found = obj
                break
        if not found:
            raise ModuleNotFoundError()
        output = self.extractAttributes(found)
        attrs  = found.getElementsByTagName("attribute")
        if len(attrnames) == 0:
            output += attrs
        else:
            for an in attrnames:
                fr = filter(lambda x:x.getAttribute("name") == an, attrs)
                if len(fr) == 0:
                    raise AttributeNotFoundError()
                elif len(fr) > 1:
                    raise AttributeDuplicationError()
                else:
                    output.append(fr[0])
        for attr in output:
            attr.setAttribute("inherited", "%s:%s" % (nspace, objname))
        return output

# Разбирает строку с наследуемыми аттрибутами
def parseInherites(inheritesStr):
    """ Разбирает строку с наследуемыми аттрибутами. 
        
        >>> list(parseInherites("a:b(c,d)"))
        [('a', 'b', ['c', 'd'])]


        >>> list(parseInherites("a:b(c,d); a(foo, bar)"))
        [('a', 'b', ['c', 'd']), (None, 'a', ['foo', 'bar'])]

        >>> list(parseInherites("x"))
        [(None, 'x', [])]

    """
    if not inheritesStr:
        return
    modules = re.split(r'\s*;\s*', inheritesStr)
    
    for module in modules:
        mr = re.match(r'((\w+):)?(\w+)(\((.*)\))?', module)
        if not mr:
            continue
        (namespace, moduleName, attrsStr) = map(mr.group, [2,3,5])
        attributes = re.split(r'\s*,\s*', attrsStr or '')
        if attributes[0] == '':
            attributes = []
        yield (namespace, moduleName, attributes) 


if __name__ == "__main__":
    import doctest
    doctest.testmod()
