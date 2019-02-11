﻿//------------------------------------------------------------------------------
// <auto-generated>
//     This code was generated by a tool.
//
//     Changes to this file may cause incorrect behavior and will be lost if
//     the code is regenerated.
// </auto-generated>
//------------------------------------------------------------------------------
#pragma once

namespace XamlBindingInfo
{
    ref class XamlBindings;

    class IXamlBindings
    {
    public:
        virtual ~IXamlBindings() {};
        virtual bool IsInitialized() = 0;
        virtual void Update() = 0;
        virtual bool SetDataRoot(::Platform::Object^ data) = 0;
        virtual void StopTracking() = 0;
        virtual void Connect(int connectionId, ::Platform::Object^ target) = 0;
        virtual void Recycle() = 0;
        virtual void ProcessBindings(::Platform::Object^ item, int itemIndex, int phase, int* nextPhase) = 0;
        virtual void SubscribeForDataContextChanged(::Windows::UI::Xaml::FrameworkElement^ object, ::XamlBindingInfo::XamlBindings^ handler) = 0;
        virtual void DisconnectUnloadedObject(int connectionId) = 0;
    };

    class IXamlBindingTracking
    {
    public:
        virtual void PropertyChanged(Platform::Object^ sender, ::Windows::UI::Xaml::Data::PropertyChangedEventArgs^ e) = 0;
        virtual void CollectionChanged(::Platform::Object^ sender, ::Windows::UI::Xaml::Interop::NotifyCollectionChangedEventArgs^ e) = 0;
        virtual void DependencyPropertyChanged(::Windows::UI::Xaml::DependencyObject^ sender, Windows::UI::Xaml::DependencyProperty^ prop) = 0;
        virtual void VectorChanged(::Platform::Object^ sender, ::Windows::Foundation::Collections::IVectorChangedEventArgs^ e) = 0;
        virtual void MapChanged(::Platform::Object^ sender, ::Windows::Foundation::Collections::IMapChangedEventArgs<::Platform::String^>^ e) = 0;
    };

    ref class XamlBindings sealed :
        ::Windows::UI::Xaml::IDataTemplateExtension,
        ::Windows::UI::Xaml::Markup::IComponentConnector,
        ::Windows::UI::Xaml::Markup::IDataTemplateComponent
    {
    internal:
        XamlBindings(::XamlBindingInfo::IXamlBindings* pBindings);
        void Initialize();
        void Update();
        void StopTracking();
        void Loading(::Windows::UI::Xaml::FrameworkElement^ src, ::Platform::Object^ data);
        void DataContextChanged(::Windows::UI::Xaml::FrameworkElement^ sender, ::Windows::UI::Xaml::DataContextChangedEventArgs^ args);
        void SubscribeForDataContextChanged(::Windows::UI::Xaml::FrameworkElement^ object);

    public:
        // IComponentConnector
        virtual void Connect(int connectionId, ::Platform::Object^ target);

        // IDataTemplateComponent
        virtual void ProcessBindings(::Platform::Object^ item, int itemIndex, int phase, int* nextPhase);
        virtual void Recycle();

        // IDataTemplateExtension
        virtual bool ProcessBinding(unsigned int);
        virtual int ProcessBindings(::Windows::UI::Xaml::Controls::ContainerContentChangingEventArgs^ args);
        virtual void ResetTemplate();

        virtual void DisconnectUnloadedObject(int connectionId);
    private:
        ~XamlBindings();
        ::XamlBindingInfo::IXamlBindings* _pBindings = nullptr;
    };

    template <class TBindingsTracking>
    class XamlBindingsBase : public IXamlBindings
    {
    protected:
        bool _isInitialized;
        TBindingsTracking^ _bindingsTracking;
        ::Windows::Foundation::EventRegistrationToken _dataContextChangedToken;
        static const int NOT_PHASED = (1 << 31);
        static const int DATA_CHANGED = (1 << 30);

    protected:
        XamlBindingsBase()
            : _isInitialized(false)
            , _bindingsTracking(nullptr)
        {
            _dataContextChangedToken.Value = 0;
        }

        virtual ~XamlBindingsBase()
        {
            if (_bindingsTracking != nullptr)
            {
                _bindingsTracking->SetListener(nullptr);
                _bindingsTracking = nullptr;
            }
        }

        virtual void ReleaseAllListeners()
        {
            // Overridden in the binding class as needed.
        }

    public:
        void InitializeTracking(::XamlBindingInfo::IXamlBindingTracking* pBindingsTracking)
        {
            _bindingsTracking = ref new TBindingsTracking();
            _bindingsTracking->SetListener(pBindingsTracking);
        }

        virtual void StopTracking() override
        {
            ReleaseAllListeners();
            this->_isInitialized = false;
        }

        virtual bool IsInitialized() override
        {
            return this->_isInitialized;
        }

        virtual void Update() = 0;

        void SubscribeForDataContextChanged(::Windows::UI::Xaml::FrameworkElement^ object, ::XamlBindingInfo::XamlBindings^ handler)
        {
            this->_dataContextChangedToken = object->DataContextChanged += 
                ref new Windows::Foundation::TypedEventHandler<::Windows::UI::Xaml::FrameworkElement^, ::Windows::UI::Xaml::DataContextChangedEventArgs^>(
                    handler, &::XamlBindingInfo::XamlBindings::DataContextChanged);
        }

        virtual void Connect(int connectionId, ::Platform::Object^ target) = 0;

        virtual void Recycle()
        {
            // Overridden in the binding class as needed.
        }

        virtual void ProcessBindings(::Platform::Object^, int, int, int* nextPhase)
        {
            // Overridden in the binding class as needed.
            *nextPhase = -1;
        }
    };

    ref class XamlBindingTrackingBase
    {
    internal:
        XamlBindingTrackingBase();
        void SetListener(::XamlBindingInfo::IXamlBindingTracking* pBindings);
        
        // Event handlers
        void PropertyChanged(Platform::Object^ sender, ::Windows::UI::Xaml::Data::PropertyChangedEventArgs^ e);
        void CollectionChanged(::Platform::Object^ sender, ::Windows::UI::Xaml::Interop::NotifyCollectionChangedEventArgs^ e);
        void DependencyPropertyChanged(::Windows::UI::Xaml::DependencyObject^ sender, Windows::UI::Xaml::DependencyProperty^ prop);
        void VectorChanged(::Platform::Object^ sender, ::Windows::Foundation::Collections::IVectorChangedEventArgs^ e);
        void MapChanged(::Platform::Object^ sender, ::Windows::Foundation::Collections::IMapChangedEventArgs<::Platform::String^>^ e);

        // Listener update functions
        void UpdatePropertyChangedListener(::Windows::UI::Xaml::Data::INotifyPropertyChanged^ obj, ::Windows::UI::Xaml::Data::INotifyPropertyChanged^* pCache, ::Windows::Foundation::EventRegistrationToken* pToken);
        void UpdatePropertyChangedListener(::Windows::UI::Xaml::Data::INotifyPropertyChanged^ obj, ::Platform::WeakReference& cacheRef, ::Windows::Foundation::EventRegistrationToken* pToken);
        void UpdateCollectionChangedListener(::Windows::UI::Xaml::Interop::INotifyCollectionChanged^ obj, ::Windows::UI::Xaml::Interop::INotifyCollectionChanged^* pCache, ::Windows::Foundation::EventRegistrationToken* pToken);
        void UpdateDependencyPropertyChangedListener(::Windows::UI::Xaml::DependencyObject^ obj, Windows::UI::Xaml::DependencyProperty^ property, ::Windows::UI::Xaml::DependencyObject^* pCache, __int64* pToken);
        void UpdateDependencyPropertyChangedListener(::Windows::UI::Xaml::DependencyObject^ obj, Windows::UI::Xaml::DependencyProperty^ property, ::Platform::WeakReference& cacheRef, __int64* pToken);

    private:
        ::XamlBindingInfo::IXamlBindingTracking* _pBindingsTrackingWeakRef = nullptr;
    };

    template <typename T>
    struct ResolveHelper
    {
        static T^ Resolve(const ::Platform::WeakReference& wr)
        {
            return wr.Resolve<T>();
        }
    };

    template <>
    struct ResolveHelper<::Platform::String>
    {
        typedef ::Platform::IBox<::Platform::String^> ResolveType;

        static ::Platform::String^ Resolve(const ::Platform::WeakReference& wr)
        {
            return safe_cast<::Platform::String^>(wr.Resolve<ResolveType>());
        }

    };

    template<class T, class TBindingsTracking> 
    class ReferenceTypeXamlBindings : public XamlBindingsBase<TBindingsTracking>
    {
    private:
        ::Platform::WeakReference _dataRoot;

    protected:
        ReferenceTypeXamlBindings() {}

        virtual void Update_(T^, int)
        {
            // Overridden in the binding class as needed.
        }

    public:
        T^ GetDataRoot()
        {
            return ResolveHelper<T>::Resolve(this->_dataRoot);
        }

        bool SetDataRoot(::Platform::Object^ data)
        {
            if (data != nullptr)
            {
                this->_dataRoot = data;
                return true;
            }
            return false;
        }

        virtual void Update() override
        {
            this->Update_(this->GetDataRoot(), this->NOT_PHASED);
            this->_isInitialized = true;
        }
    };

    template<class T, class TBindingsTracking> 
    class ValueTypeXamlBindings : public XamlBindingsBase<TBindingsTracking>
    {
    private:
        T _dataRoot;

    protected:
        ValueTypeXamlBindings() {}

        virtual void Update_(T, int)
        {
            // Overridden in the binding class as needed.
        }

    public:
        T GetDataRoot()
        {
            return this->_dataRoot;
        }

        bool SetDataRoot(::Platform::Object^ data)
        {
            if (data != nullptr)
            {
                this->_dataRoot = safe_cast<T>(data);
                return true;
            }
            return false;
        }

        virtual void Update() override
        {
            this->Update_(this->GetDataRoot(), this->NOT_PHASED);
            this->_isInitialized = true;
        }
    };
}

