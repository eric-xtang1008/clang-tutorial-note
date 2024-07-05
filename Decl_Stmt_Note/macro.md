### enum TypeClass	
	
	enum TypeClass {

	Adjusted,
	Decayed,

	ConstantArray,
	ArrayParameter,
	DependentSizedArray,
	IncompleteArray,
	VariableArray,
	Atomic,
	Attributed,
	BTFTagAttributed,
	BitInt,
	BlockPointer,

	CountAttributed,
	Builtin,
	Complex,
	Decltype,

	Auto,
	DeducedTemplateSpecialization,
	DependentAddressSpace,
	DependentBitInt,
	DependentName,
	DependentSizedExtVector,
	DependentTemplateSpecialization,
	DependentVector,
	Elaborated,

	FunctionNoProto,
	FunctionProto,
	InjectedClassName,
	MacroQualified,

	ConstantMatrix,
	DependentSizedMatrix,
	MemberPointer,
	ObjCObjectPointer,
	ObjCObject,
	ObjCInterface,
	ObjCTypeParam,
	PackExpansion,
	PackIndexing,
	Paren,
	Pipe,
	Pointer,

	LValueReference,
	RValueReference,
	SubstTemplateTypeParmPack,
	SubstTemplateTypeParm,

	Enum,
	Record,
	TemplateSpecialization,
	TemplateTypeParm,
	TypeOfExpr,
	TypeOf,
	Typedef,
	UnaryTransform,
	UnresolvedUsing,
	Using,
	Vector,
	ExtVector,

	TypeLast = ExtVector
	};


### enum Kind extend
	
	enum Kind {
    OCLImage1dRO,
    OCLImage1dArrayRO,
    OCLImage1dBufferRO,
    OCLImage2dRO,
    OCLImage2dArrayRO,
    OCLImage2dDepthRO,
    OCLImage2dArrayDepthRO,
    OCLImage2dMSAARO,
    OCLImage2dArrayMSAARO,
    OCLImage2dMSAADepthRO,
    OCLImage2dArrayMSAADepthRO,
    OCLImage3dRO,

    OCLImage1dWO,
    OCLImage1dArrayWO,
    OCLImage1dBufferWO,
    OCLImage2dWO,
    OCLImage2dArrayWO,
    OCLImage2dDepthWO,
    OCLImage2dArrayDepthWO,
    OCLImage2dMSAAWO,
    OCLImage2dArrayMSAAWO,
    OCLImage2dMSAADepthWO,
    OCLImage2dArrayMSAADepthWO,
    OCLImage3dWO,

    OCLImage1dRW,
    OCLImage1dArrayRW,
    OCLImage1dBufferRW,
    OCLImage2dRW,
    OCLImage2dArrayRW,
    OCLImage2dDepthRW,
    OCLImage2dArrayDepthRW,
    OCLImage2dMSAARW,
    OCLImage2dArrayMSAARW,
    OCLImage2dMSAADepthRW,
    OCLImage2dArrayMSAADepthRW,
    OCLImage3dRW,

    OCLIntelSubgroupAVCMcePayload,
    OCLIntelSubgroupAVCImePayload,
    OCLIntelSubgroupAVCRefPayload,
    OCLIntelSubgroupAVCSicPayload,
    OCLIntelSubgroupAVCMceResult,
    OCLIntelSubgroupAVCImeResult,
    OCLIntelSubgroupAVCRefResult,
    OCLIntelSubgroupAVCSicResult,
    OCLIntelSubgroupAVCImeResultSingleReferenceStreamout,
    OCLIntelSubgroupAVCImeResultDualReferenceStreamout,
    OCLIntelSubgroupAVCImeSingleReferenceStreamin,
    OCLIntelSubgroupAVCImeDualReferenceStreamin,

    SveInt8,
    SveInt16,
    SveInt32,
    SveInt64,

    SveUint8,
    SveUint16,
    SveUint32,
    SveUint64,

    SveFloat16,
    SveFloat32,
    SveFloat64,

    SveBFloat16,

    SveInt8x2,
    SveInt16x2,
    SveInt32x2,
    SveInt64x2,

    SveUint8x2,
    SveUint16x2,
    SveUint32x2,
    SveUint64x2,

    SveFloat16x2,
    SveFloat32x2,
    SveFloat64x2,

    SveBFloat16x2,

    SveInt8x3,
    SveInt16x3,
    SveInt32x3,
    SveInt64x3,

    SveUint8x3,
    SveUint16x3,
    SveUint32x3,
    SveUint64x3,

    SveFloat16x3,
    SveFloat32x3,
    SveFloat64x3,

    SveBFloat16x3,

    SveInt8x4,
    SveInt16x4,
    SveInt32x4,
    SveInt64x4,

    SveUint8x4,
    SveUint16x4,
    SveUint32x4,
    SveUint64x4,

    SveFloat16x4,
    SveFloat32x4,
    SveFloat64x4,

    SveBFloat16x4,

    SveBool,
    SveBoolx2,
    SveBoolx4,

    SveCount,

    VectorQuad,
    VectorPair,

    RvvInt8mf8,
    RvvInt8mf4,
    RvvInt8mf2,
    RvvInt8m1,
    RvvInt8m2,
    RvvInt8m4,
    RvvInt8m8,

    RvvUint8mf8,
    RvvUint8mf4,
    RvvUint8mf2,
    RvvUint8m1,
    RvvUint8m2,
    RvvUint8m4,
    RvvUint8m8,

    RvvInt16mf4,
    RvvInt16mf2,
    RvvInt16m1,
    RvvInt16m2,
    RvvInt16m4,
    RvvInt16m8,

    RvvUint16mf4,
    RvvUint16mf2,
    RvvUint16m1,
    RvvUint16m2,
    RvvUint16m4,
    RvvUint16m8,

    RvvInt32mf2,
    RvvInt32m1,
    RvvInt32m2,
    RvvInt32m4,
    RvvInt32m8,

    RvvUint32mf2,
    RvvUint32m1,
    RvvUint32m2,
    RvvUint32m4,
    RvvUint32m8,

    RvvInt64m1,
    RvvInt64m2,
    RvvInt64m4,
    RvvInt64m8,

    RvvUint64m1,
    RvvUint64m2,
    RvvUint64m4,
    RvvUint64m8,

    RvvFloat16mf4,
    RvvFloat16mf2,
    RvvFloat16m1,
    RvvFloat16m2,
    RvvFloat16m4,
    RvvFloat16m8,

    RvvBFloat16mf4,

    RvvBFloat16mf2,

    RvvBFloat16m1,

    RvvBFloat16m2,

    RvvBFloat16m4,

    RvvBFloat16m8,

    RvvFloat32mf2,
    RvvFloat32m1,
    RvvFloat32m2,
    RvvFloat32m4,
    RvvFloat32m8,

    RvvFloat64m1,
    RvvFloat64m2,
    RvvFloat64m4,
    RvvFloat64m8,

    RvvBool1,
    RvvBool2,
    RvvBool4,
    RvvBool8,
    RvvBool16,
    RvvBool32,
    RvvBool64,

    RvvInt8mf8x2,
    RvvInt8mf8x3,
    RvvInt8mf8x4,
    RvvInt8mf8x5,
    RvvInt8mf8x6,
    RvvInt8mf8x7,
    RvvInt8mf8x8,

    RvvInt8mf4x2,
    RvvInt8mf4x3,
    RvvInt8mf4x4,
    RvvInt8mf4x5,
    RvvInt8mf4x6,
    RvvInt8mf4x7,
    RvvInt8mf4x8,

    RvvInt8mf2x2,
    RvvInt8mf2x3,
    RvvInt8mf2x4,
    RvvInt8mf2x5,
    RvvInt8mf2x6,
    RvvInt8mf2x7,
    RvvInt8mf2x8,

    RvvInt8m1x2,
    RvvInt8m1x3,
    RvvInt8m1x4,
    RvvInt8m1x5,
    RvvInt8m1x6,
    RvvInt8m1x7,
    RvvInt8m1x8,

    RvvInt8m2x2,
    RvvInt8m2x3,
    RvvInt8m2x4,

    RvvInt8m4x2,

    RvvUint8mf8x2,
    RvvUint8mf8x3,
    RvvUint8mf8x4,
    RvvUint8mf8x5,
    RvvUint8mf8x6,
    RvvUint8mf8x7,
    RvvUint8mf8x8,

    RvvUint8mf4x2,
    RvvUint8mf4x3,
    RvvUint8mf4x4,
    RvvUint8mf4x5,
    RvvUint8mf4x6,
    RvvUint8mf4x7,
    RvvUint8mf4x8,

    RvvUint8mf2x2,
    RvvUint8mf2x3,
    RvvUint8mf2x4,
    RvvUint8mf2x5,
    RvvUint8mf2x6,
    RvvUint8mf2x7,
    RvvUint8mf2x8,

    RvvUint8m1x2,
    RvvUint8m1x3,
    RvvUint8m1x4,
    RvvUint8m1x5,
    RvvUint8m1x6,
    RvvUint8m1x7,
    RvvUint8m1x8,

    RvvUint8m2x2,
    RvvUint8m2x3,
    RvvUint8m2x4,

    RvvUint8m4x2,

    RvvInt16mf4x2,
    RvvInt16mf4x3,
    RvvInt16mf4x4,
    RvvInt16mf4x5,
    RvvInt16mf4x6,
    RvvInt16mf4x7,
    RvvInt16mf4x8,

    RvvInt16mf2x2,
    RvvInt16mf2x3,
    RvvInt16mf2x4,
    RvvInt16mf2x5,
    RvvInt16mf2x6,
    RvvInt16mf2x7,
    RvvInt16mf2x8,

    RvvInt16m1x2,
    RvvInt16m1x3,
    RvvInt16m1x4,
    RvvInt16m1x5,
    RvvInt16m1x6,
    RvvInt16m1x7,
    RvvInt16m1x8,

    RvvInt16m2x2,
    RvvInt16m2x3,
    RvvInt16m2x4,

    RvvInt16m4x2,

    RvvUint16mf4x2,
    RvvUint16mf4x3,
    RvvUint16mf4x4,
    RvvUint16mf4x5,
    RvvUint16mf4x6,
    RvvUint16mf4x7,
    RvvUint16mf4x8,

    RvvUint16mf2x2,
    RvvUint16mf2x3,
    RvvUint16mf2x4,
    RvvUint16mf2x5,
    RvvUint16mf2x6,
    RvvUint16mf2x7,
    RvvUint16mf2x8,

    RvvUint16m1x2,
    RvvUint16m1x3,
    RvvUint16m1x4,
    RvvUint16m1x5,
    RvvUint16m1x6,
    RvvUint16m1x7,
    RvvUint16m1x8,

    RvvUint16m2x2,
    RvvUint16m2x3,
    RvvUint16m2x4,

    RvvUint16m4x2,

    RvvInt32mf2x2,
    RvvInt32mf2x3,
    RvvInt32mf2x4,
    RvvInt32mf2x5,
    RvvInt32mf2x6,
    RvvInt32mf2x7,
    RvvInt32mf2x8,

    RvvInt32m1x2,
    RvvInt32m1x3,
    RvvInt32m1x4,
    RvvInt32m1x5,
    RvvInt32m1x6,
    RvvInt32m1x7,
    RvvInt32m1x8,

    RvvInt32m2x2,
    RvvInt32m2x3,
    RvvInt32m2x4,

    RvvInt32m4x2,

    RvvUint32mf2x2,
    RvvUint32mf2x3,
    RvvUint32mf2x4,
    RvvUint32mf2x5,
    RvvUint32mf2x6,
    RvvUint32mf2x7,
    RvvUint32mf2x8,

    RvvUint32m1x2,
    RvvUint32m1x3,
    RvvUint32m1x4,
    RvvUint32m1x5,
    RvvUint32m1x6,
    RvvUint32m1x7,
    RvvUint32m1x8,

    RvvUint32m2x2,
    RvvUint32m2x3,
    RvvUint32m2x4,

    RvvUint32m4x2,

    RvvInt64m1x2,
    RvvInt64m1x3,
    RvvInt64m1x4,
    RvvInt64m1x5,
    RvvInt64m1x6,
    RvvInt64m1x7,
    RvvInt64m1x8,

    RvvInt64m2x2,
    RvvInt64m2x3,
    RvvInt64m2x4,

    RvvInt64m4x2,

    RvvUint64m1x2,
    RvvUint64m1x3,
    RvvUint64m1x4,
    RvvUint64m1x5,
    RvvUint64m1x6,
    RvvUint64m1x7,
    RvvUint64m1x8,

    RvvUint64m2x2,
    RvvUint64m2x3,
    RvvUint64m2x4,

    RvvUint64m4x2,

    RvvFloat16mf4x2,
    RvvFloat16mf4x3,
    RvvFloat16mf4x4,
    RvvFloat16mf4x5,
    RvvFloat16mf4x6,
    RvvFloat16mf4x7,
    RvvFloat16mf4x8,

    RvvFloat16mf2x2,
    RvvFloat16mf2x3,
    RvvFloat16mf2x4,
    RvvFloat16mf2x5,
    RvvFloat16mf2x6,
    RvvFloat16mf2x7,
    RvvFloat16mf2x8,

    RvvFloat16m1x2,
    RvvFloat16m1x3,
    RvvFloat16m1x4,
    RvvFloat16m1x5,
    RvvFloat16m1x6,
    RvvFloat16m1x7,
    RvvFloat16m1x8,

    RvvFloat16m2x2,
    RvvFloat16m2x3,
    RvvFloat16m2x4,

    RvvFloat16m4x2,

    RvvFloat32mf2x2,
    RvvFloat32mf2x3,
    RvvFloat32mf2x4,
    RvvFloat32mf2x5,
    RvvFloat32mf2x6,
    RvvFloat32mf2x7,
    RvvFloat32mf2x8,

    RvvFloat32m1x2,
    RvvFloat32m1x3,
    RvvFloat32m1x4,
    RvvFloat32m1x5,
    RvvFloat32m1x6,
    RvvFloat32m1x7,
    RvvFloat32m1x8,

    RvvFloat32m2x2,
    RvvFloat32m2x3,
    RvvFloat32m2x4,

    RvvFloat32m4x2,

    RvvFloat64m1x2,
    RvvFloat64m1x3,
    RvvFloat64m1x4,
    RvvFloat64m1x5,
    RvvFloat64m1x6,
    RvvFloat64m1x7,
    RvvFloat64m1x8,

    RvvFloat64m2x2,
    RvvFloat64m2x3,
    RvvFloat64m2x4,

    RvvFloat64m4x2,

    RvvBFloat16mf4x2,

    RvvBFloat16mf4x3,

    RvvBFloat16mf4x4,

    RvvBFloat16mf4x5,

    RvvBFloat16mf4x6,

    RvvBFloat16mf4x7,

    RvvBFloat16mf4x8,

    RvvBFloat16mf2x2,

    RvvBFloat16mf2x3,

    RvvBFloat16mf2x4,

    RvvBFloat16mf2x5,

    RvvBFloat16mf2x6,

    RvvBFloat16mf2x7,

    RvvBFloat16mf2x8,

    RvvBFloat16m1x2,

    RvvBFloat16m1x3,

    RvvBFloat16m1x4,

    RvvBFloat16m1x5,

    RvvBFloat16m1x6,

    RvvBFloat16m1x7,

    RvvBFloat16m1x8,

    RvvBFloat16m2x2,

    RvvBFloat16m2x3,

    RvvBFloat16m2x4,

    RvvBFloat16m4x2,

    WasmExternRef,

    Void,

    Bool,

    Char_U,

    UChar,

    WChar_U,

    Char8,

    Char16,

    Char32,

    UShort,

    UInt,

    ULong,

    ULongLong,

    UInt128,

    Char_S,

    SChar,

    WChar_S,

    Short,

    Int,

    Long,

    LongLong,

    Int128,

    ShortAccum,

    Accum,

    LongAccum,

    UShortAccum,

    UAccum,

    ULongAccum,

    ShortFract,

    Fract,

    LongFract,

    UShortFract,

    UFract,

    ULongFract,

    SatShortAccum,

    SatAccum,

    SatLongAccum,

    SatUShortAccum,

    SatUAccum,

    SatULongAccum,

    SatShortFract,

    SatFract,

    SatLongFract,

    SatUShortFract,

    SatUFract,

    SatULongFract,

    Half,

    Float,

    Double,

    LongDouble,

    Float16,

    BFloat16,

    Float128,

    Ibm128,

    NullPtr,

    ObjCId,

    ObjCClass,

    ObjCSel,

    OCLSampler,

    OCLEvent,

    OCLClkEvent,

    OCLQueue,

    OCLReserveID,

    Dependent,
    Overload,

    BoundMember,

    UnresolvedTemplate,
    PseudoObject,

    UnknownAny,

    BuiltinFn,

    ARCUnbridgedCast,

    IncompleteMatrixIdx,

    ArraySection,

    OMPArrayShaping,

    OMPIterator,

    LastKind = OMPIterator
  };