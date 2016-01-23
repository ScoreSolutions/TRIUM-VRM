<%@ Page Title="" Language="VB" MasterPageFile="~/ContentMasterPage.master" AutoEventWireup="false" CodeFile="frmSelectRoom.aspx.vb" Inherits="frmSelectRoom" %>

<asp:Content ID="Content1" ContentPlaceHolderID="ContentPlaceHolder1" runat="Server">
    <form id="form1" runat="server">
        <div class="main-content">
            <div class="breadcrumbs" id="breadcrumbs">
                <ul class="breadcrumb">
                    <li>
                        <i class="icon-home home-icon"></i>
                        <a href="frmMain.aspx">Home</a>

                        <span class="divider">
                            <i class="icon-angle-right arrow-icon"></i>
                        </span>
                    </li>
                    <li>

                        <a href="frmRequestRoom.aspx">Search Room</a>

                        <span class="divider">
                            <i class="icon-angle-right arrow-icon"></i>
                        </span>
                    </li>
                    <li class="active">Booking Room</li>
                </ul>
                <!--.breadcrumb-->

                <%--            <div class="nav-search" id="nav-search">
                <form class="form-search" />
                <span class="input-icon">
                    <input type="text" placeholder="Search ..." class="input-small nav-search-input" id="nav-search-input" autocomplete="off" />
                    <i class="icon-search nav-search-icon"></i>
                </span>
                </form>
            </div>--%>
                <!--#nav-search-->
            </div>

            <div class="page-content">


                <div class="row-fluid">
                    <div class="span12">
                        <!--PAGE CONTENT BEGINS-->


                        <div class="row-fluid">
                            <h3 class="header smaller lighter blue">Booking Room</h3>
                            <%--     <div class="table-header">
                            View Demo
                        </div>--%>


                            <div class="dt_out_actions" style="display: none">
                                <div class="btn-group pull-Left">
                                    <button class="btn btn-app btn-info btn-mini no-radius" id="btnPrint" name="btnPrint">
                                        <i class="icon-print bigger-100"></i>
                                        Print
                                    </button>
                                    <button class="btn btn-app btn-success btn-mini no-radius" id="btnAddnew" name="btnAddnew">
                                        <i class="icon-folder-open bigger-100"></i>
                                        Add New
                                    </button>
                                    <button class="btn btn-app btn-danger btn-mini no-radius" id="btnDelete" name="btnDelete">
                                        <i class="icon-trash bigger-100"></i>
                                        Delete
                                    </button>

                                </div>
                            </div>
                        </div>
                        <%-- <table class="table table-striped table-bordered table-hover" id="dt_out"></table>--%>
                        <!--/PAGE CONTENT BEGINS-->

                        <div class="row-fluid">
                            <div class="span12">


                                <iframe id="iFrame" runat="server" frameborder="0" style="overflow: hidden; height: 450px; width: 100%" src="frmSlotRoom.aspx"></iframe>


                                <!--/PAGE CONTENT END-->

                            </div>

                        </div>
                        <!--/.span-->
                    </div>
                    <!--/.row-fluid-->

                    <!--/.page-content-->

                    <div class="ace-settings-container" id="ace-settings-container">
                        <div class="btn btn-app btn-mini btn-warning ace-settings-btn" id="ace-settings-btn">
                            <i class="icon-cog bigger-150"></i>
                        </div>

                        <div class="ace-settings-box" id="ace-settings-box">
                            <div>
                                <div class="pull-left">
                                    <select id="skin-colorpicker" class="hide">
                                        <option data-class="default" value="#438EB9" />
                                        #438EB9
									<option data-class="skin-1" value="#222A2D" />
                                        #222A2D
									<option data-class="skin-2" value="#C6487E" />
                                        #C6487E
									<option data-class="skin-3" value="#D0D0D0" />
                                        #D0D0D0
                                    </select>
                                </div>
                                <span>&nbsp; Choose Skin</span>
                            </div>

                            <div>
                                <input type="checkbox" class="ace-checkbox-2" id="ace-settings-header" />
                                <label class="lbl" for="ace-settings-header">Fixed Header</label>
                            </div>

                            <div>
                                <input type="checkbox" class="ace-checkbox-2" id="ace-settings-sidebar" />
                                <label class="lbl" for="ace-settings-sidebar">Fixed Sidebar</label>
                            </div>

                            <div>
                                <input type="checkbox" class="ace-checkbox-2" id="ace-settings-breadcrumbs" />
                                <label class="lbl" for="ace-settings-breadcrumbs">Fixed Breadcrumbs</label>
                            </div>

                            <div>
                                <input type="checkbox" class="ace-checkbox-2" id="ace-settings-rtl" />
                                <label class="lbl" for="ace-settings-rtl">Right To Left (rtl)</label>
                            </div>
                        </div>
                    </div>
                    <!--/#ace-settings-container-->
                </div>
            </div>
        </div>
    </form>
</asp:Content>

