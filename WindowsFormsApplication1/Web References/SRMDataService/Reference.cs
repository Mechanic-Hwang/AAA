﻿//------------------------------------------------------------------------------
// <auto-generated>
//     This code was generated by a tool.
//     Runtime Version:4.0.30319.18408
//
//     Changes to this file may cause incorrect behavior and will be lost if
//     the code is regenerated.
// </auto-generated>
//------------------------------------------------------------------------------

// 
// This source code was auto-generated by Microsoft.VSDesigner, Version 4.0.30319.18408.
// 
#pragma warning disable 1591

namespace WindowsFormsApplication1.SRMDataService {
    using System;
    using System.Web.Services;
    using System.Diagnostics;
    using System.Web.Services.Protocols;
    using System.Xml.Serialization;
    using System.ComponentModel;
    
    
    /// <remarks/>
    [System.CodeDom.Compiler.GeneratedCodeAttribute("System.Web.Services", "4.0.30319.18408")]
    [System.Diagnostics.DebuggerStepThroughAttribute()]
    [System.ComponentModel.DesignerCategoryAttribute("code")]
    [System.Web.Services.WebServiceBindingAttribute(Name="SRMDataServiceSoap", Namespace="http://tempuri.org/")]
    public partial class SRMDataService : System.Web.Services.Protocols.SoapHttpClientProtocol {
        
        private System.Threading.SendOrPostCallback transSRMTaskOperationCompleted;
        
        private System.Threading.SendOrPostCallback transSRMTaskAisleOperationCompleted;
        
        private bool useDefaultCredentialsSetExplicitly;
        
        /// <remarks/>
        public SRMDataService() {
            this.Url = global::WindowsFormsApplication1.Properties.Settings.Default.WindowsFormsApplication1_SRMDataService_SRMDataService;
            if ((this.IsLocalFileSystemWebService(this.Url) == true)) {
                this.UseDefaultCredentials = true;
                this.useDefaultCredentialsSetExplicitly = false;
            }
            else {
                this.useDefaultCredentialsSetExplicitly = true;
            }
        }
        
        public new string Url {
            get {
                return base.Url;
            }
            set {
                if ((((this.IsLocalFileSystemWebService(base.Url) == true) 
                            && (this.useDefaultCredentialsSetExplicitly == false)) 
                            && (this.IsLocalFileSystemWebService(value) == false))) {
                    base.UseDefaultCredentials = false;
                }
                base.Url = value;
            }
        }
        
        public new bool UseDefaultCredentials {
            get {
                return base.UseDefaultCredentials;
            }
            set {
                base.UseDefaultCredentials = value;
                this.useDefaultCredentialsSetExplicitly = true;
            }
        }
        
        /// <remarks/>
        public event transSRMTaskCompletedEventHandler transSRMTaskCompleted;
        
        /// <remarks/>
        public event transSRMTaskAisleCompletedEventHandler transSRMTaskAisleCompleted;
        
        /// <remarks/>
        [System.Web.Services.Protocols.SoapDocumentMethodAttribute("http://tempuri.org/transSRMTask", RequestNamespace="http://tempuri.org/", ResponseNamespace="http://tempuri.org/", Use=System.Web.Services.Description.SoapBindingUse.Literal, ParameterStyle=System.Web.Services.Protocols.SoapParameterStyle.Wrapped)]
        public string transSRMTask(string wcsProductObject) {
            object[] results = this.Invoke("transSRMTask", new object[] {
                        wcsProductObject});
            return ((string)(results[0]));
        }
        
        /// <remarks/>
        public void transSRMTaskAsync(string wcsProductObject) {
            this.transSRMTaskAsync(wcsProductObject, null);
        }
        
        /// <remarks/>
        public void transSRMTaskAsync(string wcsProductObject, object userState) {
            if ((this.transSRMTaskOperationCompleted == null)) {
                this.transSRMTaskOperationCompleted = new System.Threading.SendOrPostCallback(this.OntransSRMTaskOperationCompleted);
            }
            this.InvokeAsync("transSRMTask", new object[] {
                        wcsProductObject}, this.transSRMTaskOperationCompleted, userState);
        }
        
        private void OntransSRMTaskOperationCompleted(object arg) {
            if ((this.transSRMTaskCompleted != null)) {
                System.Web.Services.Protocols.InvokeCompletedEventArgs invokeArgs = ((System.Web.Services.Protocols.InvokeCompletedEventArgs)(arg));
                this.transSRMTaskCompleted(this, new transSRMTaskCompletedEventArgs(invokeArgs.Results, invokeArgs.Error, invokeArgs.Cancelled, invokeArgs.UserState));
            }
        }
        
        /// <remarks/>
        [System.Web.Services.Protocols.SoapDocumentMethodAttribute("http://tempuri.org/transSRMTaskAisle", RequestNamespace="http://tempuri.org/", ResponseNamespace="http://tempuri.org/", Use=System.Web.Services.Description.SoapBindingUse.Literal, ParameterStyle=System.Web.Services.Protocols.SoapParameterStyle.Wrapped)]
        public string transSRMTaskAisle(string wcsProductObject) {
            object[] results = this.Invoke("transSRMTaskAisle", new object[] {
                        wcsProductObject});
            return ((string)(results[0]));
        }
        
        /// <remarks/>
        public void transSRMTaskAisleAsync(string wcsProductObject) {
            this.transSRMTaskAisleAsync(wcsProductObject, null);
        }
        
        /// <remarks/>
        public void transSRMTaskAisleAsync(string wcsProductObject, object userState) {
            if ((this.transSRMTaskAisleOperationCompleted == null)) {
                this.transSRMTaskAisleOperationCompleted = new System.Threading.SendOrPostCallback(this.OntransSRMTaskAisleOperationCompleted);
            }
            this.InvokeAsync("transSRMTaskAisle", new object[] {
                        wcsProductObject}, this.transSRMTaskAisleOperationCompleted, userState);
        }
        
        private void OntransSRMTaskAisleOperationCompleted(object arg) {
            if ((this.transSRMTaskAisleCompleted != null)) {
                System.Web.Services.Protocols.InvokeCompletedEventArgs invokeArgs = ((System.Web.Services.Protocols.InvokeCompletedEventArgs)(arg));
                this.transSRMTaskAisleCompleted(this, new transSRMTaskAisleCompletedEventArgs(invokeArgs.Results, invokeArgs.Error, invokeArgs.Cancelled, invokeArgs.UserState));
            }
        }
        
        /// <remarks/>
        public new void CancelAsync(object userState) {
            base.CancelAsync(userState);
        }
        
        private bool IsLocalFileSystemWebService(string url) {
            if (((url == null) 
                        || (url == string.Empty))) {
                return false;
            }
            System.Uri wsUri = new System.Uri(url);
            if (((wsUri.Port >= 1024) 
                        && (string.Compare(wsUri.Host, "localHost", System.StringComparison.OrdinalIgnoreCase) == 0))) {
                return true;
            }
            return false;
        }
    }
    
    /// <remarks/>
    [System.CodeDom.Compiler.GeneratedCodeAttribute("System.Web.Services", "4.0.30319.18408")]
    public delegate void transSRMTaskCompletedEventHandler(object sender, transSRMTaskCompletedEventArgs e);
    
    /// <remarks/>
    [System.CodeDom.Compiler.GeneratedCodeAttribute("System.Web.Services", "4.0.30319.18408")]
    [System.Diagnostics.DebuggerStepThroughAttribute()]
    [System.ComponentModel.DesignerCategoryAttribute("code")]
    public partial class transSRMTaskCompletedEventArgs : System.ComponentModel.AsyncCompletedEventArgs {
        
        private object[] results;
        
        internal transSRMTaskCompletedEventArgs(object[] results, System.Exception exception, bool cancelled, object userState) : 
                base(exception, cancelled, userState) {
            this.results = results;
        }
        
        /// <remarks/>
        public string Result {
            get {
                this.RaiseExceptionIfNecessary();
                return ((string)(this.results[0]));
            }
        }
    }
    
    /// <remarks/>
    [System.CodeDom.Compiler.GeneratedCodeAttribute("System.Web.Services", "4.0.30319.18408")]
    public delegate void transSRMTaskAisleCompletedEventHandler(object sender, transSRMTaskAisleCompletedEventArgs e);
    
    /// <remarks/>
    [System.CodeDom.Compiler.GeneratedCodeAttribute("System.Web.Services", "4.0.30319.18408")]
    [System.Diagnostics.DebuggerStepThroughAttribute()]
    [System.ComponentModel.DesignerCategoryAttribute("code")]
    public partial class transSRMTaskAisleCompletedEventArgs : System.ComponentModel.AsyncCompletedEventArgs {
        
        private object[] results;
        
        internal transSRMTaskAisleCompletedEventArgs(object[] results, System.Exception exception, bool cancelled, object userState) : 
                base(exception, cancelled, userState) {
            this.results = results;
        }
        
        /// <remarks/>
        public string Result {
            get {
                this.RaiseExceptionIfNecessary();
                return ((string)(this.results[0]));
            }
        }
    }
}

#pragma warning restore 1591