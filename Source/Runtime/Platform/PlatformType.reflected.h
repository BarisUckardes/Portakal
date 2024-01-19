#pragma warning(push)
#pragma warning( disable : 4067)
#undef PENUM()
#define PENUM(...)\
 enum class PlatformType : Int64;\
	template<>\
	class TypeAccessor<PlatformType>\
	{\
		friend class TypeDispatcher;\
	public:\
		static Type* GetType()\
		{\
			return sType;\
		}\
	private:\
		static void SetType(Type* pType)\
		{\
			sType = pType;\
		}\
		static Type** GetTypeAddress()\
		{\
			return &sType;\
		}\
	private:\
		static inline Type* sType = nullptr;\
	};
    #undef GENERATE_OBJECT;
    #define GENERATE_OBJECT friend ReflectionManifest* ::GenerateModuleManifest(); virtual Type* GetType() const noexcept override {return typeof(PlatformType);}
    #pragma warning( pop )
