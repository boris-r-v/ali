#ifndef _ALI_TAG_EVENT
#define _ALI_TAG_EVENT

#include <map>
#include <mutex>
#include <list>
#include <functional>
#include <type_traits>
#include <boost/variant.hpp>

namespace ali
{
    class Tag;
    enum TagType {TAG_BOOLEAN, TAG_NUMERIC, TAG_STRING, TAG_NUM_TYPES};
    static const std::string TagTypeName[TAG_NUM_TYPES]={"boolean", "numeric", "string"};
    class TagWrongTypeException: public std::exception
    {
	    std::string const msg;
	public:
	    TagWrongTypeException( Tag const&, TagType ) throw();
	    virtual ~TagWrongTypeException( ) throw();
	    virtual const char* what() const throw();
    };

    class Tag
    {
	    typedef bool				boolean_type;
	    typedef double 				numeric_type;
	    typedef std::string				string_type;
	    typedef boost::variant<boolean_type, numeric_type, string_type > value_t;
    	    std::string name_;
	    value_t value_;

	public:
	    std::string const& get_name() const;
	    TagType get_type() const;
	    bool get_boolean() const;
	    double get_numeric() const;
	    std::string get_string() const;

	    template <class T > Tag( std::string const& _n, T const& _v ):name_(_n ) 
	    { 
		set(_v); 
	    }
	    template <class T > Tag& operator=( T const& v ){ set( v ); return *this; }
	    template <typename T> operator T() const { return get<T>(); }
	    template <typename T> T get() const
	    {
		T value;
		get_internal(value);
		return value;
	    }

	private:
        template <typename T> struct is_boolean : public std::is_same<boolean_type, T> {};
        template <typename T> struct is_numeric : std::integral_constant <bool, std::is_arithmetic<T>::value && !is_boolean<T>::value > {};
        template <typename T> struct is_string  : std::integral_constant <bool, std::is_same<std::string, T>::value || std::is_same<const char*, T>::value > {};

        template<typename T, std::enable_if_t< is_boolean<T>::value, int > = 0 > 
        void set(T _value ) //, typename st::enable_if<is_boolean<T> >::type* = NULL)
        {
            value_ = boolean_type(_value);
        }
        template<typename T, std::enable_if_t< is_numeric<T>::value, int> = 0 >
        void set(T _value ) //, typename boost::enable_if<is_numeric<T> >::type* = NULL)
        {
            value_ = numeric_type(_value);
        }
        template<typename T, std::enable_if_t< is_string<T>::value, int > = 0 >
        void set(T _value ) //, typename boost::enable_if<is_string<T> >::type* = NULL)
        {
            value_ = string_type(_value);
        }

        template<typename T, std::enable_if_t< is_boolean<T>::value, int > = 0 > 
        void get_internal(T &_value ) const// , typename boost::enable_if<is_boolean<T> >::type* = NULL) const
        {
            if(get_type() != TAG_BOOLEAN) throw TagWrongTypeException(*this, TAG_BOOLEAN);
            _value = boost::get<boolean_type>(value_);
        }
        template<typename T, std::enable_if_t< is_numeric<T>::value, int > = 0 >
        void get_internal(T &_value ) const//, typename boost::enable_if<is_numeric<T> >::type* = NULL) const
        {
            if(get_type() != TAG_NUMERIC) throw TagWrongTypeException(*this, TAG_NUMERIC);
            _value = boost::get<numeric_type>(value_);
        }
        template<typename T, std::enable_if_t< is_string<T>::value, int > = 0 >
        void get_internal(T &_value ) const//, typename boost::enable_if<is_string<T> >::type* = NULL) const
        {
            if(get_type() != TAG_STRING) throw TagWrongTypeException(*this, TAG_STRING);
            _value = boost::get<string_type>(value_);
        }

	    friend std::ostream& operator << ( std::ostream&, Tag const& );    
    };
    std::ostream& operator << ( std::ostream&, Tag const& );    

    class TagService
    {
	    std::map<std::string, std::list< std::function< void ( ali::Tag const&) > > > map_;
    	    std::mutex lock_;
	    TagService() = default;
	public:
	    static TagService& Instance();
	    ~TagService() = default;
	    
	    void add_reciever ( std::string const&, std::function< void ( ali::Tag const&) > ); 
	    void emit_tag( Tag const& );
    };

    template <class T> void emit_tag (std::string const& _name, T const& _data ) 
    { 
	ali::TagService::Instance().emit_tag( Tag(_name, _data) ); 
    }     
    void subs_tag (std::string const& _name, std::function< void ( ali::Tag const&) > _func );

}
#endif //_ALI_TAG_EVENT