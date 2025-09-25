//--------------------------------------------------------------------*- C++ -*-
// typedefs for function pointers with signatures matching required CppInterOp API
//-----------------------------------------------------------------------------

#ifndef CPPINTEROP_FUNC_PTR_TYPEDEFS_H
#define CPPINTEROP_FUNC_PTR_TYPEDEFS_H

#include <cstddef>
#include <cstdint>
#include <string>
#include <vector>

// preprocessor macro to check if we use the dispatch mechanism
#include <CppInterOp/CppInterOpDispatch.h>
// using namespace CppFinal = CppDispatch;

// using namespace CppFinal = Cpp;

namespace CppAPIType {

using GetVersion = std::string (*)();

using Demangle = std::string (*)(const std::string& mangled_name);

using EnableDebugOutput = void (*)(bool value);

using IsDebugOutputEnabled = bool (*)();

using IsAggregate = bool (*)(Cpp::TCppScope_t scope);

using IsNamespace = bool (*)(Cpp::TCppScope_t scope);

using IsClass = bool (*)(Cpp::TCppScope_t scope);

using IsFunction = bool (*)(Cpp::TCppScope_t scope);

using IsFunctionPointerType = bool (*)(Cpp::TCppType_t type);

using IsClassPolymorphic = bool (*)(Cpp::TCppScope_t klass);

using IsComplete = bool (*)(Cpp::TCppScope_t scope);

using SizeOf = size_t (*)(Cpp::TCppScope_t scope);

using IsBuiltin = bool (*)(Cpp::TCppType_t type);

using IsTemplate = bool (*)(Cpp::TCppScope_t handle);

using IsTemplateSpecialization = bool (*)(Cpp::TCppScope_t handle);

using IsTypedefed = bool (*)(Cpp::TCppScope_t handle);

using IsAbstract = bool (*)(Cpp::TCppType_t klass);

using IsEnumScope = bool (*)(Cpp::TCppScope_t handle);

using IsEnumConstant = bool (*)(Cpp::TCppScope_t handle);

using IsEnumType = bool (*)(Cpp::TCppType_t type);

using HasTypeQualifier = bool (*)(Cpp::TCppType_t type, Cpp::QualKind qual);

using RemoveTypeQualifier = Cpp::TCppType_t (*)(Cpp::TCppType_t type, Cpp::QualKind qual);

using AddTypeQualifier = Cpp::TCppType_t (*)(Cpp::TCppType_t type, Cpp::QualKind qual);

using GetEnums = void (*)(Cpp::TCppScope_t scope, std::vector<Cpp::TCppScope_t>& Result);

using IsSmartPtrType = bool (*)(Cpp::TCppType_t type);

using GetIntegerTypeFromEnumScope = Cpp::TCppType_t (*)(Cpp::TCppScope_t handle);

using GetIntegerTypeFromEnumType = Cpp::TCppType_t (*)(Cpp::TCppType_t handle);

using GetEnumConstants = std::vector<Cpp::TCppScope_t> (*)(Cpp::TCppScope_t scope);

using GetEnumConstantType = Cpp::TCppType_t (*)(Cpp::TCppScope_t scope);

using GetEnumConstantValue = Cpp::TCppIndex_t (*)(Cpp::TCppScope_t scope);

using GetSizeOfType = size_t (*)(Cpp::TCppType_t type);

using IsVariable = bool (*)(Cpp::TCppScope_t scope);

using GetName = std::string (*)(Cpp::TCppScope_t klass);

using GetCompleteName = std::string (*)(Cpp::TCppScope_t klass);

using GetQualifiedName = std::string (*)(Cpp::TCppScope_t klass);

using GetQualifiedCompleteName = std::string (*)(Cpp::TCppScope_t klass);

using GetUsingNamespaces = std::vector<Cpp::TCppScope_t> (*)(Cpp::TCppScope_t scope);

using GetGlobalScope = Cpp::TCppScope_t (*)();

using GetUnderlyingScope = Cpp::TCppScope_t (*)(Cpp::TCppScope_t scope);

using GetScope = Cpp::TCppScope_t (*)(const std::string& name, Cpp::TCppScope_t parent);

using GetScopeFromCompleteName = Cpp::TCppScope_t (*)(const std::string& name);

using GetNamed = Cpp::TCppScope_t (*)(const std::string& name, Cpp::TCppScope_t parent);

using GetParentScope = Cpp::TCppScope_t (*)(Cpp::TCppScope_t scope);

using GetScopeFromType = Cpp::TCppScope_t (*)(Cpp::TCppType_t type);

using GetNumBases = Cpp::TCppIndex_t (*)(Cpp::TCppScope_t klass);

using GetBaseClass = Cpp::TCppScope_t (*)(Cpp::TCppScope_t klass, Cpp::TCppIndex_t ibase);

using IsSubclass = bool (*)(Cpp::TCppScope_t derived, Cpp::TCppScope_t base);

using GetBaseClassOffset = int64_t (*)(Cpp::TCppScope_t derived, Cpp::TCppScope_t base);

using GetClassMethods = void (*)(Cpp::TCppScope_t klass, std::vector<Cpp::TCppScope_t>& methods);

using GetFunctionTemplatedDecls = void (*)(Cpp::TCppScope_t klass, std::vector<Cpp::TCppScope_t>& methods);

using HasDefaultConstructor = bool (*)(Cpp::TCppScope_t scope);

using GetDefaultConstructor = Cpp::TCppFunction_t (*)(Cpp::TCppScope_t scope);

using GetDestructor = Cpp::TCppFunction_t (*)(Cpp::TCppScope_t scope);

using GetFunctionsUsingName = std::vector<Cpp::TCppFunction_t> (*)(Cpp::TCppScope_t scope, const std::string& name);

using GetFunctionReturnType = Cpp::TCppType_t (*)(Cpp::TCppFunction_t func);

using GetFunctionNumArgs = Cpp::TCppIndex_t (*)(Cpp::TCppFunction_t func);

using GetFunctionRequiredArgs = Cpp::TCppIndex_t (*)(Cpp::TCppConstFunction_t func);

using GetFunctionArgType = Cpp::TCppType_t (*)(Cpp::TCppFunction_t func, Cpp::TCppIndex_t iarg);

using GetFunctionSignature = std::string (*)(Cpp::TCppFunction_t func);

using IsFunctionDeleted = bool (*)(Cpp::TCppConstFunction_t function);

using IsTemplatedFunction = bool (*)(Cpp::TCppFunction_t func);

using ExistsFunctionTemplate = bool (*)(const std::string& name, Cpp::TCppScope_t parent);

using GetClassTemplatedMethods = bool (*)(const std::string& name, Cpp::TCppScope_t parent, std::vector<Cpp::TCppFunction_t>& funcs);

using IsMethod = bool (*)(Cpp::TCppConstFunction_t method);

using IsPublicMethod = bool (*)(Cpp::TCppFunction_t method);

using IsProtectedMethod = bool (*)(Cpp::TCppFunction_t method);

using IsPrivateMethod = bool (*)(Cpp::TCppFunction_t method);

using IsConstructor = bool (*)(Cpp::TCppConstFunction_t method);

using IsDestructor = bool (*)(Cpp::TCppConstFunction_t method);

using IsStaticMethod = bool (*)(Cpp::TCppConstFunction_t method);

using GetFunctionAddressFromName = Cpp::TCppFuncAddr_t (*)(const char* mangled_name);

using GetFunctionAddressFromMethod = Cpp::TCppFuncAddr_t (*)(Cpp::TCppFunction_t method);

using IsVirtualMethod = bool (*)(Cpp::TCppFunction_t method);

using GetDatamembers = void (*)(Cpp::TCppScope_t scope, std::vector<Cpp::TCppScope_t>& datamembers);

using GetStaticDatamembers = void (*)(Cpp::TCppScope_t scope, std::vector<Cpp::TCppScope_t>& datamembers);

using GetEnumConstantDatamembers = void (*)(Cpp::TCppScope_t scope, std::vector<Cpp::TCppScope_t>& datamembers, bool include_enum_class);

using LookupDatamember = Cpp::TCppScope_t (*)(const std::string& name, Cpp::TCppScope_t parent);

using IsLambdaClass = bool (*)(Cpp::TCppType_t type);

using GetVariableType = Cpp::TCppType_t (*)(Cpp::TCppScope_t var);

using GetVariableOffset = intptr_t (*)(Cpp::TCppScope_t var, Cpp::TCppScope_t parent);

using IsPublicVariable = bool (*)(Cpp::TCppScope_t var);

using IsProtectedVariable = bool (*)(Cpp::TCppScope_t var);

using IsPrivateVariable = bool (*)(Cpp::TCppScope_t var);

using IsStaticVariable = bool (*)(Cpp::TCppScope_t var);

using IsConstVariable = bool (*)(Cpp::TCppScope_t var);

using IsRecordType = bool (*)(Cpp::TCppType_t type);

using IsPODType = bool (*)(Cpp::TCppType_t type);

using IsPointerType = bool (*)(Cpp::TCppType_t type);

using GetPointeeType = Cpp::TCppType_t (*)(Cpp::TCppType_t type);

using IsReferenceType = bool (*)(Cpp::TCppType_t type);

using IsLValueReferenceType = bool (*)(Cpp::TCppType_t type);

using IsRValueReferenceType = bool (*)(Cpp::TCppType_t type);

using GetPointerType = Cpp::TCppType_t (*)(Cpp::TCppType_t type);

using GetReferencedType = Cpp::TCppType_t (*)(Cpp::TCppType_t type, bool rvalue);

using GetNonReferenceType = Cpp::TCppType_t (*)(Cpp::TCppType_t type);

using GetTypeAsString = std::string (*)(Cpp::TCppType_t type);

using GetCanonicalType = Cpp::TCppType_t (*)(Cpp::TCppType_t type);

using JitCallMakeFunctionCallable = Cpp::JitCall (*)(Cpp::TCppConstFunction_t func);

using IsConstMethod = bool (*)(Cpp::TCppFunction_t method);

using GetFunctionArgDefault = std::string (*)(Cpp::TCppFunction_t func, Cpp::TCppIndex_t param_index);

using GetFunctionArgName = std::string (*)(Cpp::TCppFunction_t func, Cpp::TCppIndex_t param_index);

using GetSpellingFromOperator = std::string (*)(Cpp::Operator op);

using GetOperatorFromSpelling = Cpp::Operator (*)(const std::string& op);

using GetOperatorArity = Cpp::OperatorArity (*)(Cpp::TCppFunction_t op);

using GetOperator = void (*)(Cpp::TCppScope_t scope, Cpp::Operator op, std::vector<Cpp::TCppFunction_t>& operators, Cpp::OperatorArity kind);

using CreateInterpreter = Cpp::TInterp_t (*)(const std::vector<const char*>& Args, const std::vector<const char*>& GpuArgs);

using DeleteInterpreter = bool (*)(Cpp::TInterp_t interp);

using ActivateInterpreter = bool (*)(Cpp::TInterp_t interp);

using GetInterpreter = Cpp::TInterp_t (*)();

using UseExternalInterpreter = void (*)(Cpp::TInterp_t interp);

using AddSearchPath = void (*)(const char* dir, bool isUser, bool prepend);

using GetResourceDir = const char* (*)();

using DetectResourceDir = std::string (*)(const char* ClangBinaryName);

using DetectSystemCompilerIncludePaths = void (*)(std::vector<std::string>& Paths, const char* CompilerName);

using AddIncludePath = void (*)(const char* dir);

using GetIncludePaths = void (*)(std::vector<std::string>& IncludePaths, bool withSystem, bool withFlags);

using Declare = int (*)(const char* code, bool silent);

using Process = int (*)(const char* code);

using Evaluate = intptr_t (*)(const char* code, bool* HadError);

using LookupLibrary = std::string (*)(const char* lib_name);

using LoadLibrary = bool (*)(const char* lib_stem, bool lookup);

using UnloadLibrary = void (*)(const char* lib_stem);

using SearchLibrariesForSymbol = std::string (*)(const char* mangled_name, bool search_system);

using InsertOrReplaceJitSymbol = bool (*)(const char* linker_mangled_name, uint64_t address);

using ObjToString = std::string (*)(const char* type, void* obj);

using GetUnderlyingType = Cpp::TCppType_t (*)(Cpp::TCppType_t type);

using BestOverloadFunctionMatch  = Cpp::TCppFunction_t(*)(const std::vector<Cpp::TCppFunction_t>& candidates,
                          const std::vector<Cpp::TemplateArgInfo>& explicit_types,
                          const std::vector<Cpp::TemplateArgInfo>& arg_types);
using GetFunctionPrototype = std::string (*)(Cpp::TCppFunction_t func);

using GetDimensions = std::vector<long int> (*)(Cpp::TCppType_t var);

using DumpScope = void (*)(Cpp::TCppScope_t scope);

using GetClassTemplateInstantiationArgs = void (*)(Cpp::TCppScope_t klass, std::vector<Cpp::TemplateArgInfo>& args);

using GetAllCppNames = void (*)(Cpp::TCppScope_t scope, std::set<std::string>& names);

using Deallocate = void(*)(Cpp::TCppScope_t scope, Cpp::TCppObject_t address, Cpp::TCppIndex_t count);

using Allocate = Cpp::TCppObject_t(*)(Cpp::TCppScope_t scope, Cpp::TCppIndex_t count);

using InstantiateTemplate = Cpp::TCppScope_t(*)(Cpp::TCppScope_t tmpl, const Cpp::TemplateArgInfo* template_args, size_t template_args_size, bool instantiate_body);

using GetComplexType = Cpp::TCppType_t(*)(Cpp::TCppType_t type);

using GetTypeFromScope = Cpp::TCppType_t(*)(Cpp::TCppScope_t klass);

using GetType = Cpp::TCppType_t(*)(const std::string& type);

using Construct = Cpp::TCppObject_t(*)(Cpp::TCppScope_t scope, Cpp::TCppObject_t arena, Cpp::TCppIndex_t count);

using Destruct = bool(*)(Cpp::TCppObject_t This, Cpp::TCppScope_t scope, bool withFree, Cpp::TCppIndex_t count);

using MakeFunctionCallable = Cpp::JitCall(*)(Cpp::TCppConstFunction_t func);
using GetFunctionAddress = Cpp::TCppFuncAddr_t(*)(Cpp::TCppConstFunction_t func);
} // namespace Cpp

#endif // CPPINTEROP_FUNC_PTR_TYPEDEFS_H


// GetInterpreter;
// CreateInterpreter;
// Process;
// GetResourceDir;
// AddIncludePath;
// LoadLibrary;
// Declare;
// DeleteInterpreter;
// IsNamespace;
// ObjToString;
// GetQualifiedCompleteName;
// IsLValueReferenceType;
// GetNonReferenceType;
// IsEnumType;
// GetIntegerTypeFromEnumType;
// GetReferencedType;
// IsPointerType;
// GetPointeeType;
// GetPointerType;
// IsReferenceType;
// GetTypeAsString;
// GetCanonicalType;
// HasTypeQualifier;
// RemoveTypeQualifier;
// GetUnderlyingType;
// IsRecordType;
// IsFunctionPointerType;
// GetVariableType;
// GetNamed;
// GetScopeFromType;
// GetClassTemplateInstantiationArgs;
// IsClass;
// GetType;
// GetTypeFromScope;
// GetComplexType;
// GetIntegerTypeFromEnumScope;
// GetUnderlyingScope;
// GetScope;
// GetGlobalScope;
// GetScopeFromCompleteName;
// InstantiateTemplate;
// GetParentScope;
// IsTemplate;
// IsTemplateSpecialization;
// IsTypedefed;
// IsClassPolymorphic;
// Demangle;
// SizeOf;
// GetSizeOfType;
// IsBuiltin;
// IsComplete;
// Allocate;
// Deallocate;
// Construct;
// Destruct;
// MakeFunctionCallable;
// GetFunctionAddress;
// IsAbstract;
// IsEnumScope;
// IsEnumConstant;
// IsAggregate;
// HasDefaultConstructor;
// IsVariable;
// GetAllCppNames;
// GetUsingNamespaces;
// GetCompleteName;
// GetDestructor;
// IsVirtualMethod;
// GetNumBases;
// GetName;
// GetBaseClass;
// IsSubclass;
// GetOperator;
// GetFunctionReturnType;
// GetBaseClassOffset;
// GetClassMethods;
// GetFunctionsUsingName;
// GetFunctionNumArgs;
// GetFunctionRequiredArgs;
// GetFunctionArgName;
// GetFunctionArgType;
// GetFunctionArgDefault;
// GetFunctionPrototype;
// IsConstMethod;
// GetFunctionTemplatedDecls;
// ExistsFunctionTemplate;
// IsTemplatedFunction;
// IsStaticMethod;
// GetClassTemplatedMethods;
// BestOverloadFunctionMatch;
// GetOperatorFromSpelling;
// IsFunctionDeleted;
// IsPublicMethod;
// IsProtectedMethod;
// IsPrivateMethod;
// IsConstructor;
// IsDestructor;
// GetDatamembers;
// GetStaticDatamembers;
// GetEnumConstantDatamembers;
// LookupDatamember;
// IsLambdaClass;
// GetQualifiedName;
// GetVariableOffset;
// IsPublicVariable;
// IsProtectedVariable;
// IsPrivateVariable;
// IsStaticVariable;
// IsConstVariable;
// GetDimensions;
// GetEnumConstants;
// GetEnumConstantType;
// GetEnumConstantValue;
// DumpScope;
