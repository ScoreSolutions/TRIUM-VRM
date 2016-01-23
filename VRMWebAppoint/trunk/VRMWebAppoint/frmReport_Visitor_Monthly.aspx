<%@ Page Title="" Language="VB" MasterPageFile="~/ContentMasterPage.master" AutoEventWireup="false" CodeFile="frmReport_Visitor_Monthly.aspx.vb" Inherits="frmReport_Visitor_Monthly" %>

<asp:Content ID="Content1" ContentPlaceHolderID="ContentPlaceHolder1" Runat="Server">
     <form id="form1" runat="server">
         <asp:ScriptManager ID="ScriptManager1" runat="server"></asp:ScriptManager>
         <asp:UpdatePanel ID="UpdatePanel1" runat="server">
             <ContentTemplate>

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
                             <li class="active">Visitor report by monthly</li>
                         </ul>
                         <!--.breadcrumb-->


                         <!--#nav-search-->
                     </div>

                     <div class="page-content">


                         <div class="row-fluid">
                             <div class="span12">
                                 <!--PAGE CONTENT BEGINS-->


                                 <div class="row-fluid">
                                     <h3 class="header smaller lighter blue">Visitor report by monthly</h3>


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

                                 <!--/PAGE CONTENT BEGINS-->

                                 <div class="row-fluid">
                                     <div class="span2">
                                         <label class="control-label" for="lblBuilding">Building</label>
                                     </div>
                                     <div class="span4">
                                         <select class="chzn-select" id="cbBuilding" data-placeholder="Choose a Building...">
                                         </select>
                                     </div>
                                     <div class="span2">
                                         <label class="control-label" for="lblRoom">Room</label>
                                     </div>
                                     <div class="span4">
                                         <select class="chzn-select" id="cbRoom" data-placeholder="Choose a Room ...">
                                         </select>
                                     </div>
                                 </div>


                                 <div class="row-fluid">
                                     <div class="span2">
                                         <label class="control-label" for="lblBuilding">Year From</label>
                                     </div>
                                     <div class="span4">
                                         <select class="chzn-select" id="cbYearFrom" data-placeholder="Choose Year From...">
                                         </select>
                                     </div>
                                     <div class="span2">
                                         <label class="control-label" for="lblRoomType">Year To</label>
                                     </div>
                                     <div class="span4">
                                         <select class="chzn-select" id="cbYearTo" data-placeholder="Choose Year To ...">
                                         </select>
                                     </div>
                                 </div>

                                 <div class="row-fluid">
                                     <div class="span2">
                                         <label class="control-label" for="lblBuilding">Month From</label>
                                     </div>
                                     <div class="span4">
                                         <select class="chzn-select" id="cbMonthFrom" data-placeholder="Choose Month From...">
                                         </select>
                                     </div>
                                     <div class="span2">
                                         <label class="control-label" for="lblRoomType">Month To</label>
                                     </div>
                                     <div class="span4">
                                         <select class="chzn-select" id="cbMonthTo" data-placeholder="Choose Month To ...">
                                         </select>
                                     </div>
                                 </div>

                                 <br />
                                 <br />
                                 <div class="row-fluid">
                                     <div class="span4">
                                         <label class="control-label" for="lblBuilding2"></label>
                                     </div>
                                     <div class="span8">
                                         <button class="btn btn-info" type="button" id="btnSearch">
                                             <i class="icon-ok bigger-110"></i>
                                             Preview
                                         </button>


                                         &nbsp; &nbsp; &nbsp;
									<button class="btn" type="reset" id="btnClear">
                                        <i class="icon-undo bigger-110"></i>
                                        Clear
                                    </button>
                                     </div>

                                 </div>
                             </div>
                             <div class="row-fluid">
                                 <br />
                                 <div>
                                     <h3 class="header smaller lighter blue">Show Report</h3>
                                 </div>
                             </div>
                             <div class="row-fluid">
                                 <div class="span12">
                                     <button class="btn btn-danger btn-small" type="button" runat="server" id="btnExport" style="display: none">
                                         <i class="icon-reply icon-only"></i>
                                         Export
                                     </button>
                                 </div>
                             </div>

                             <div class="row-fluid">
                                 <div class="span12">
                                     <br />
                                     <div id="divShowTable"></div>
                                     <br />
                                     <br />
                                     <center>
                                        <label id="lbldatanotfound" class="lighter blue" style="font-size:larger;display:none">Data Not Found.</label>
                             </center>
                                 </div>
                             </div>

                             <!--/PAGE CONTENT END-->
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
             </ContentTemplate>
         </asp:UpdatePanel>
        <script type="text/javascript">
            $(function () {

                populateSelect();

                $('#cbBuilding').change(function () {
                    populateSelectRoom();
                });

                $('#cbRoom').change(function () {
                    populateSelectBuilding();
                });

                //Search
                $("#btnSearch").click(function () {
                    populateTable();
                });
                //Export
                $('#' + '<%=btnExport.ClientID%>').click(function () {
                    populateExport();
                });

                $("#btnClear").click(function () {
                    clearInput();
                });
              
                //ปฎิธิน
                $('.date-picker').datepicker().next().on(ace.click_event, function () {

                    $(this).prev().focus();
                });

              
            });

        </script>
         <script type="text/javascript">
             function clearInput() {
                 $('#' + '<%=btnExport.ClientID%>').hide();
                $('#divShowTable').hide();
                populateSelect();
             }

             function populateExport() {
                 var buildingid = $('#cbBuilding').val();
                 var roomid = $('#cbRoom').val();
                 var yearfrom = $('#cbYearFrom').val();
                 var yearto = $('#cbYearTo').val();
                 var monthfrom = $('#cbMonthFrom').val();
                 var monthto = $("#cbMonthTo").val();
                 var para = '?buildingid=' + buildingid + '&roomid=' + roomid + '&yearfrom=' + yearfrom + '&yearto=' + yearto + '&monthfrom =' + monthfrom + '&monthto =' + monthto;

                 var dataurl = 'frmReport_Visitor_Monthly.ashx' + para;
                 window.location.href = dataurl;
             }

             function populateTable() {
                 var buildingid = $('#cbBuilding').val();
                 var roomid = $('#cbRoom').val();
                 var yearfrom = $('#cbYearFrom').val();
                 var yearto = $('#cbYearTo').val();
                 var monthfrom = $('#cbMonthFrom').val();
                 var monthto = $("#cbMonthTo").val();
                 var param = "{'buildingid':" + JSON.stringify(buildingid)
                             + ",'roomid':" + JSON.stringify(roomid)
                             + ",'yearfrom':" + JSON.stringify(yearfrom)
                             + ",'yearto':" + JSON.stringify(yearto) 
                             + ",'monthfrom':" + JSON.stringify(monthfrom) 
                             + ",'monthto':" + JSON.stringify(monthto) + "}";
                 $table = $("#divShowTable");
                 $.ajax({
                     type: "POST",
                     url: 'WebSevice/WebService.asmx/RenderVisitorMonthly',
                     dataType: 'JSON',
                     data: param,
                     contentType: "application/json; charset=utf-8",
                     success: function (data) {
                         //var jsonobject = JSON.parse(data.d);
                         if (data.d != '') {
                             //clear 
                             $table.html('');
                             $table.append(data.d);
                             $("#lbldatanotfound").hide();
                             $('#divShowTable').show();
                             $('#' + '<%=btnExport.ClientID%>').show();
                         } else {
                             $("#lbldatanotfound").show();
                         }
                     }
                 });
             }

             function populateSelectRoom() {
                 var strselect;
                 var id = $('#cbBuilding').val();
                 var param = "{'id':" + JSON.stringify(id) + "}";
                 $selectRoom = $('#cbRoom');
                 var id_room_selected = $selectRoom.val();

                 $.ajax({
                     type: "POST",
                     url: 'WebSevice/WebService.asmx/LoadRoomByBuildingId',
                     dataType: 'JSON',
                     data: param,
                     contentType: "application/json; charset=utf-8",
                     success: function (data) {
                         var jsonobject = JSON.parse(data.d);

                         //clear 
                         $selectRoom.html('');
                         $selectRoom.append('<option value="">Choose all</option>');
                         //append a select option
                         $.each(jsonobject, function (key, val) {
                             strselect = '';
                             if (id_room_selected == val.id) {
                                 strselect = ' selected="' + val.selected + '"';
                             }
                             $selectRoom.append('<option value="' + val.id + '" ' + strselect + '>' + val.room_name + '</option>');
                             $selectRoom.trigger("liszt:updated");//update select option

                         })
                         $selectRoom.trigger("liszt:updated");//update select option

                     }
                 });
             }

             function populateSelectBuilding() {
                 var strselect;
                 var id = $('#cbRoom').val();
                 var param = "{'id':" + JSON.stringify(id) + "}";
                 $selectBuilding = $("#cbBuilding");
                 var id_building_selected = $selectBuilding.val();
                 $.ajax({
                     type: "POST",
                     url: 'WebSevice/WebService.asmx/LoadBuildingByRoomId',
                     dataType: 'JSON',
                     data: param,
                     contentType: "application/json; charset=utf-8",
                     success: function (data) {
                         var jsonobject = JSON.parse(data.d);
                         //clear 
                         $selectBuilding.html('');
                         $selectBuilding.append('<option value="">Choose all</option>');
                         //append a select option
                         $.each(jsonobject, function (key, val) {
                             strselect = '';
                             if (id_building_selected == val.id) {
                                 strselect = ' selected="' + val.selected + '"';
                             }
                             $selectBuilding.append('<option value="' + val.id + '" ' + strselect + '>' + val.building_name + '</option>');
                             $selectBuilding.trigger("liszt:updated");//update select option
                         })
                         $selectBuilding.trigger("liszt:updated");//update select option
                     }
                 });

             }

             function populateSelect() {
                 $selectRoom = $('#cbRoom');
                 //$selectRoom = $("#cbRoom");
                 $.ajax({
                     type: "POST",
                     url: 'WebSevice/WebService.asmx/LoadActiveRoom',
                     dataType: 'JSON',
                     contentType: "application/json; charset=utf-8",
                     success: function (data) {
                         var jsonobject = JSON.parse(data.d);

                         //clear 
                         $selectRoom.html('');
                         $selectRoom.append('<option value="">Choose all</option>');
                         //append a select option
                         $.each(jsonobject, function (key, val) {
                             $selectRoom.append('<option value="' + val.id + '">' + val.room_name + '</option>');
                             $selectRoom.trigger("liszt:updated");//update select option
                         })
                     }
                 });

                 $selectBuilding = $("#cbBuilding");
                 $.ajax({
                     type: "POST",
                     url: 'WebSevice/WebService.asmx/LoadActiveBuliding',
                     dataType: 'JSON',
                     contentType: "application/json; charset=utf-8",
                     success: function (data) {
                         var jsonobject = JSON.parse(data.d);
                         //clear 
                         $selectBuilding.html('');
                         $selectBuilding.append('<option value="">Choose all</option>');
                         //append a select option
                         $.each(jsonobject, function (key, val) {

                             $selectBuilding.append('<option value="' + val.id + '">' + val.building_name + '</option>');
                             $selectBuilding.trigger("liszt:updated");//update select option
                         })
                     }
                 });

                 $selectYearFrom = $("#cbYearFrom");
                 $selectYearTo = $("#cbYearTo");
                 var numberofyear = 10;
                 var param = "{'numberofyear':" + JSON.stringify(numberofyear) + "}";
                 $.ajax({
                     type: "POST",
                     url: 'WebSevice/WebService.asmx/GetYear',
                     dataType: 'JSON',
                     data: param,
                     contentType: "application/json; charset=utf-8",
                     success: function (data) {
                         var jsonobject = JSON.parse(data.d);
                         //clear 
                         $selectYearFrom.html('');
                         $selectYearFrom.append('<option value="">Choose all</option>');
                         $selectYearTo.html('');
                         $selectYearTo.append('<option value="">Choose all</option>');
                         //append a select option
                         $.each(jsonobject, function (key, val) {
                             $selectYearFrom.append('<option value="' + val.id + '">' + val.year + '</option>');
                             $selectYearFrom.trigger("liszt:updated");//update select option

                             $selectYearTo.append('<option value="' + val.id + '">' + val.year + '</option>');
                             $selectYearTo.trigger("liszt:updated");//update select option
                         })
                     }
                 });

                 $selectMonthFrom = $("#cbMonthFrom");
                 $selectMonthTo = $("#cbMonthTo");
                 $.ajax({
                     type: "POST",
                     url: 'WebSevice/WebService.asmx/GetMonthEng',
                     dataType: 'JSON',
                     data: param,
                     contentType: "application/json; charset=utf-8",
                     success: function (data) {
                         var jsonobject = JSON.parse(data.d);
                         //clear 
                         $selectMonthFrom.html('');
                         $selectMonthFrom.append('<option value="">Choose all</option>');
                         $selectMonthTo.html('');
                         $selectMonthTo.append('<option value="">Choose all</option>');
                         //append a select option
                         $.each(jsonobject, function (key, val) {
                             $selectMonthFrom.append('<option value="' + val.id + '">' + val.month + '</option>');
                             $selectMonthFrom.trigger("liszt:updated");//update select option

                             $selectMonthTo.append('<option value="' + val.id + '">' + val.month + '</option>');
                             $selectMonthTo.trigger("liszt:updated");//update select option
                         })
                     }
                 });

                 //Combo Box  
                 $(".chzn-select").chosen();
             }
         </script>
    </form>
</asp:Content>

