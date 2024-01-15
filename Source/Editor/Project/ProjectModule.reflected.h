#pragma warning(push)
#pragma warning( disable : 4067)
#undef PCLASS()
#define PCLASS(...)\
 class ProjectModule;\
	template<>\
	class TypeAccessor<ProjectModule>\
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
    #define GENERATE_OBJECT virtual Type* GetType() const noexcept override {return typeof(ProjectModule);}
    #pragma warning( pop )
