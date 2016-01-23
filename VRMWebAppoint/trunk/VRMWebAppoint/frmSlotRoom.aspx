<%@ Page Language="VB" AutoEventWireup="false" CodeFile="frmSlotRoom.aspx.vb" Inherits="frmSlotRoom" %>

<!DOCTYPE html>
<html>
<head>
    <meta http-equiv="Content-type" content="text/html; charset=utf-8">
    <title></title>



    <script type="text/javascript">
        window.jQuery || document.write("<script src='assets/js/jquery-2.0.3.min.js'>" + "<" + "/script>");
    </script>

    <script src="assets/js/jquery-ui-1.11.1.js"></script>
    <link href="assets/themes/start/jquery-ui.css" rel="stylesheet" />


    <%--    <script src="Demo2/dhtmlxScheduler_v4.2.0/codebase/dhtmlxscheduler.js" type="text/javascript" charset="utf-8"></script>
    <script src="Demo2/dhtmlxScheduler_v4.2.0/codebase/ext/dhtmlxscheduler_timeline.js" type="text/javascript" charset="utf-8"></script>
    <script src="Demo2/dhtmlxScheduler_v4.2.0/ccodebase/ext/dhtmlxscheduler_limit.js"  type="text/javascript" charset="utf-8" ></script>
    <script src="Demo2/dhtmlxScheduler_v4.2.0/ccodebase/ext/dhtmlxscheduler_timeline.js"  type="text/javascript" charset="utf-8"></script>
    <script src="Demo2/dhtmlxScheduler_v4.2.0/codebase/ext/dhtmlxscheduler_multiselect.js"></script>
    <script src="Demo2/dhtmlxScheduler_v4.2.0/codebase/ext/dhtmlxscheduler_units.js"></script>--%>

    <script src="Demo2/dhtmlxScheduler_v4.2.0/codebase/dhtmlxscheduler.js" type="text/javascript" charset="utf-8"></script>
    <script src="Demo2/dhtmlxScheduler_v4.2.0/codebase/ext/dhtmlxscheduler_multisection.js" type="text/javascript" charset="utf-8"></script>

    <link rel="stylesheet" href="Demo2/dhtmlxScheduler_v4.2.0/codebase/dhtmlxscheduler.css" type="text/css" media="screen" title="no title" charset="utf-8">

    <script src="Demo2/dhtmlxScheduler_v4.2.0/codebase/ext/dhtmlxscheduler_limit.js" type="text/javascript" charset="utf-8"></script>
    <script src='Demo2/dhtmlxScheduler_v4.2.0/codebase/ext/dhtmlxscheduler_timeline.js' type="text/javascript" charset="utf-8"></script>
    <script src="Demo2/dhtmlxScheduler_v4.2.0/codebase/ext/dhtmlxscheduler_units.js" type="text/javascript" charset="utf-8"></script>
    <script src="Demo2/dhtmlxScheduler_v4.2.0/codebase/ext/dhtmlxscheduler_multiselect.js" type="text/javascript" charset="utf-8"></script>
    <script src="Demo2/dhtmlxScheduler_v4.2.0/codebase/ext/dhtmlxscheduler_editors.js" type="text/javascript" charset="utf-8"></script>

    <%-- <script src="../../codebase/ext/dhtmlxscheduler_limit.js" type="text/javascript" charset="utf-8"></script>
	<script src='../../codebase/ext/dhtmlxscheduler_timeline.js' type="text/javascript" charset="utf-8"></script>
	<script src="../../codebase/ext/dhtmlxscheduler_units.js" type="text/javascript" charset="utf-8"></script>
	<script src="../../codebase/ext/dhtmlxscheduler_multiselect.js" type="text/javascript" charset="utf-8"></script>--%>

    <link rel='stylesheet' type='text/css' href='Demo2/dhtmlxScheduler_v4.2.0/codebase/dhtmlxscheduler.css'>

    <style type="text/css" media="screen">
        html, body {
            margin: 0px;
            padding: 0px;
            height: 100%;
            overflow: hidden;
        }

        h1 {
            border-bottom: 8px solid #57c4d0;
            font-size: 24px;
            display: inline-block;
        }

        .title {
            border-bottom: 1px solid #dedede;
            margin-bottom: 20px;
        }
    </style>




    <script type="text/javascript" charset="utf-8">

        //$(function () {
        //    $("btnBack").click(function () {
        //        topLocation('/frmRequestRoom.aspx');
        //    });

        //})

        var topLocation = function (url) {
            var hostfolder = '';
            var pathArray = window.location.pathname.split('/');
            if (pathArray.length >= 3) {
                hostfolder = '/' + pathArray[1];
            }


            // make sure its a relative url
            if (url[0] === '/' && url[1] !== '/') {
                // x-broswer window.location.origin 
                if (!window.location.origin) window.location.origin = window.location.protocol + "//" + window.location.host;
                window.top.location = window.location.origin + hostfolder + url;
            } else {
                window.top.location = +hostfolder + url;
            }
        }

        function ReFeshPage() {
            location.reload();

        }
        function onConfirm() {


            var evs = scheduler.getEvents();
            //var sec = scheduler.getSection(1);
            //var evs = scheduler.getEvents(new Date(2013, 1, 10), new Date(2013, 2, 10));
            // alert(sec);
            if (evs.length == 0) {
                // alert('Booking meeting rooms');
                onAlert('Please select room and time for booking meeting room');
                return;
            }

            var msg = 'Please confirm the booking';
            var div = $("<div>" + msg + "</div>");
            div.dialog({
                title: "Confirm",
                modal: true,
                buttons: [
                            {
                                text: "Yes",
                                click: function () {
                                    div.dialog("close");
                                    onSave();
                                }
                            },
                            {
                                text: "No",
                                click: function () {
                                    div.dialog("close");
                                }
                            }
                ]
            });



        }
        function onAlert(msg) {

            var div = $("<div>" + msg + "</div>");
            div.dialog({
                title: "Message",
                modal: true,
                buttons: [

                            {
                                text: "Ok",
                                click: function () {
                                    div.dialog("close");

                                }
                            }
                ]
            });

        }
        function onSave() {
            var evs = scheduler.getEvents();
            //var sec = scheduler.getSection(1);
            //var evs = scheduler.getEvents(new Date(2013, 1, 10), new Date(2013, 2, 10));
            // alert(sec);
            if (evs.length == 0) {
                // alert('Booking meeting rooms');
                onAlert('Please select room and time for booking meeting room');
            }
            //else if (evs.length > 1) {
            //    // alert('Booking meeting rooms');
            //    onAlert('Please select room and time for booking meeting room 1 record');
            //}
            else {
                for (var i = 0; i < evs.length; i++) {

                    //alert(evs[i].id);
                    //alert(evs[i].text);
                    //alert(evs[i].start_date);
                    //alert(evs[i].end_date);
                    //alert(evs[i].section_id);

                    var sd = new Date();
                    var ed = new Date();
                    //sd.format("yyyy/MM/dd hh:mm");
                    //ed.format("yyyy/MM/dd hh:mm");
                    sd = evs[i].start_date;
                    ed = evs[i].end_date;
                    var scurr_date = sd.getDate();
                    var scurr_month = sd.getMonth();
                    var scurr_year = sd.getFullYear();
                    var scurr_minutes = AddZero(sd.getHours()) + ':' + AddZero(sd.getMinutes());
                    var ecurr_date = ed.getDate();
                    var ecurr_month = ed.getMonth();
                    var ecurr_year = ed.getFullYear();
                    var ecurr_minutes = AddZero(ed.getHours()) + ':' + AddZero(ed.getMinutes());
                    var sdate = scurr_month + "/" + scurr_date + "/" + scurr_year;
                    var edate = ecurr_month + "/" + ecurr_date + "/" + ecurr_year;

                    // var temp = '{ 'start_date'': '' + sdate + ', 'end_date': '' + edate + '', text: ' + edate + ', section_id: ' + evs[i].section_id + ', id: ' + evs[i].id + ' }';
                    // var temp = "{'start_date':'" + sdate + "','end_date':'" + end_date + "','text':'" + evs[i].text + "','section_id':'" + evs[i].section_id + "',id:'" + evs[i].id + "' }";
                    //temp = temp + ',{ start_date: "2014-11-19 10:00", end_date: "2014-11-19 16:00", text: "ประชุมโครงการปี 2558 วาระ 2", section_id: 1, id: 2 }]';
                    // alert(temp);
                    // var temp = "{'name':'" + name + "','age':'" + age + "','sex':'" + sex + "'}";
                    // alert(temp);
                    //var strPurpose = $("#hPurpose").val();
                    //var strBuilding = $("#hBuilding").val();
                    //var strid = $("#hUserid").val();
                    var strpurpose = localStorage['purpose'];
                    var strattendant = localStorage['attendant'];
                    var strbuilding_id = localStorage['building_id'];
                    var strroomtype_id = localStorage['roomtype_id'];
                    var stroption_id = localStorage['stroption_id'];
                    var struserid = localStorage['userid'];

                    onSaveDatabase(sd, ed, evs[i].text, evs[i].section_id, struserid, scurr_minutes, ecurr_minutes, strpurpose);
                    //topLocation('/frmCompletRoom.aspx');
                    //return;
                }
            }


        }

        function AddZero(num) {
            return (num >= 0 && num < 10) ? "0" + num : num + "";
        }

        function onSaveDatabase(sdate, edate, txt, room_id, userid, starttime, endtime, purpose) {

           // var param = "{'start_date':" + JSON.stringify(sdate) + ",'end_date':" + JSON.stringify(edate) + ",'text':" + JSON.stringify(text) + ",'section_id':" + JSON.stringify(section_id) + ",'id':" + JSON.stringify(id) + ",'stime':" + JSON.stringify(stime) + ",'etime':" + JSON.stringify(etime) + ",'purpose':" + JSON.stringify(purpose) + ",'building':" + JSON.stringify(building) + "}";

            var param = "{'id':" + JSON.stringify(0)
                         + ",'startdate':" + JSON.stringify(sdate)
                         + ",'enddate':" + JSON.stringify(edate)
                         + ",'starttime':" + JSON.stringify(starttime)
                         + ",'endtime':" + JSON.stringify(endtime)
                         + ",'room_id':" + JSON.stringify(room_id)
                         + ",'purpose':" + JSON.stringify(purpose)
                         + ",'strvisitor':" + JSON.stringify('')
                         + ",'active_status':" + JSON.stringify('Y')
                         + ",'userid':" + JSON.stringify(userid)
                         + "}"

            // var param = "{'strID':" + JSON.stringify(value) + "}";

            $.ajax({
                type: "POST",
                url: "WebSevice/WebService.asmx/SaveBooking",
                data: param,
                contentType: "application/json; charset=utf-8",
                dataType: "json",
                success: onSuccess,
                error: onFailed
            });

            //alert(strTemp.replace('#',''));

            //onAlert("Save Call Function");
        }
        function onSuccess(result) {

            if (result.d != 0) {
                // onAlert("Booking Complete");
                localStorage['prebooking_id'] = result.d;
                topLocation('/frmCompletRoom.aspx?RowIDMenu=20');
            }
            else if (result.d = -1) {
                onAlert("Date and time duplicate Please modify date or time ");
            } else {
                onAlert("Booking Fail");
            }

        }

        function onFailed() {
            onAlert("Booking Fail");
        }

        //$("#btnSave").click(function () {
        //    onConfirm(); return false;
        //});

        //$("#btnClear").click(function () {
        //    ReFeshPage(); return false;
        //});

        //function getRoombyContition() {
        //    var returnvalue;
        //    var param = "{'id':" + JSON.stringify(0) + "}";
        //    $.ajax({
        //        type: "POST",
        //        url: "WebSevice/WebService.asmx/LoadRoombyContition",
        //        data: param,
        //        contentType: "application/json; charset=utf-8",
        //        dataType: "json",
        //        success: function (data) {
        //            //  returnvalue = data.d;
        //            localStorage['roomdata'] = data.d
        //        },
        //        error: onFailed
        //    });

        //    //var roomsections = [];
        //    //var roomsections = JSON.parse(getRoombyContition());
        //    // alert(returnvalue);
        //    //  return returnvalue;

        //}

        function init() {
            //scheduler.config.multi_day = false;
            //scheduler.config.multisection = false;

            scheduler.config.xml_date = "%Y-%m-%d %H:%i";

            scheduler.locale.labels.timeline_tab = "Timeline";
            scheduler.locale.labels.unit_tab = "Unit";

            scheduler.locale.labels.section_custom = "Section";
            scheduler.config.details_on_create = true;
            scheduler.config.details_on_dblclick = true;


            //===============
            //Configuration
            //===============
            //<img src="http://www.sclawson.ca/corrie/Images/Smileys/43.gif" alt="" />
            //<img src="../../../../assets/images/gallery/image-1.jpg" alt="" />
            //var sections = [
            //	{ key: 1, label: "<div><img src='images/Room1.jpg' height='180px' width='100%' />Meeting Room 1</div>" },
            //	{ key: 2, label: "<div><img src='images/Room2.jpg' height='180px' width='100%' />Meeting Room 2</div>" },
            //	{ key: 3, label: "<div><img src='images/Room3.jpg' height='180px' width='100%' />Meeting Room 3</div>" },
            //	{ key: 4, label: "<div><img src='images/Room4.jpg' height='180px' width='100%' />Meeting Room 4</div>" }
            //];
            //var roomsections = [];
            //var roomsections = JSON.parse(getRoombyContition());
           // getRoombyContition();
            var sections = JSON.parse(localStorage['roomdata']);
           // alert(sections);
            // sections = JSON.parse(localStorage['roomdata']);
            //   alert(roomsections);


            var durations = {
                day: 24 * 60 * 60 * 1000,
                hour: 60 * 60 * 1000,
                minute: 60 * 1000
            };

            var get_formatted_duration = function (start, end) {
                var diff = end - start;

                var days = Math.floor(diff / durations.day);
                diff -= days * durations.day;
                var hours = Math.floor(diff / durations.hour);
                diff -= hours * durations.hour;
                var minutes = Math.floor(diff / durations.minute);

                var results = [];
                if (days) results.push(days + " days");
                if (hours) results.push(hours + " hours");
                if (minutes) results.push(minutes + " minutes");
                return results.join(", ");
            };


            var resize_date_format = scheduler.date.date_to_str(scheduler.config.hour_date);

            scheduler.templates.event_bar_text = function (start, end, event) {
                var state = scheduler.getState();
                if (state.drag_id == event.id) {
                    return resize_date_format(start) + " - " + resize_date_format(end) + " (" + get_formatted_duration(start, end) + ")";
                }
                return event.text; // default


            };

            scheduler.createTimelineView({
                name: "timeline",
                x_unit: "minute",
                x_date: "%H:%i",
                x_step: 30,
                x_size: 24,
                x_start: 16,
                x_length: 48,
                y_unit: sections,
                y_property: "section_id",
                render: "bar",
                event_dy: "full",
                section_autoheight: false,
                dx: 200,
                dy: 200
            });


            //===============
            //Customization
            //===============

            scheduler.createUnitsView({
                name: "unit",
                property: "section_id",
                list: sections
            });



            var blocks = JSON.parse(localStorage['roomtimedata']);
            // alert(blocks);
            if (blocks.length > 0) {
                 $.each(blocks, function (key, val) {

                                scheduler.addMarkedTimespan({
                                    start_date: new Date(val.syear, parseInt(val.smonth) - 1, val.sday, val.sh, val.sminute),
                                    end_date: new Date(val.syear, parseInt(val.smonth) - 1, val.sday, val.eh, val.eminute),
                                    //start_date: new Date(2015, 0, 18, 8, 0),
                                    //end_date: new Date(2015, 0, 18, 9, 30),
                                    type: "dhx_time_block",
                                    sections: {
                                        timeline: val.id, // only 1 section
                                        unit: val.id
                                    }
                                });
                            })
            }
   

            //===============
            //Data loading
            //===============
            scheduler.config.lightbox.sections = [
				{ name: "description", height: 130, map_to: "text", type: "textarea", focus: true },
				{ name: "custom", height: 23, type: "select", options: sections, map_to: "section_id" },
				{ name: "time", height: 72, type: "time", map_to: "auto" }
            ];
            //var temp = '[{ start_date: "2014-11-19 09:00", end_date: "2014-11-19 12:00", text: "ประชุมโครงการปี 2558 วาระ 1", section_id: 1, id: 1 }';
            //temp = temp + ',{ start_date: "2014-11-19 10:00", end_date: "2014-11-19 16:00", text: "ประชุมโครงการปี 2558 วาระ 2", section_id: 1, id: 2 }]';
            // alert(temp);
            // var json = JSON.stringify(eval("(" + temp + ")"));
            var json = JSON.stringify(eval("([])"));

            var strfulldate = localStorage['roomdate'];
            var strtemp = strfulldate.split("/");
            var strday, strmonth, stryear;
            strday = strtemp[0];
            strmonth = strtemp[1];
            stryear = strtemp[2];

            //alert(strday);
            //alert(strmonth);
            //alert(stryear);



            scheduler.init('scheduler_here', new Date(stryear, parseInt(strmonth) -1, strday), "timeline");
            scheduler.parse(json, "json");


            //scheduler.addMarkedTimespan({
            //    //start_date: new Date(2014, 11, 25),
            //    //end_date: new Date(2014, 11, 25),
            //    //type: "dhx_time_block",
            //    //sections: {
            //    //    timeline: 2, // only 1 section
            //    //    unit: 1
            //    //}
            //    type: "dhx_time_block",
            //    days: new Date(2014, 11, 25),
            //    zones: [4 * 60, 8 * 60, 12 * 60, 15 * 60],
            //    css: "gray",
            //    sections: {unit: 1}
            //});
            //scheduler.blockTime(new Date(2014, 11, 25), "fullday");
            //scheduler.updateView();

            //var eventId = scheduler.addEvent({
            //    start_date: "2014-11-19 09:00",
            //    end_date: "2014-11-19 12:00",
            //    text: "test"
            //});

            //var eventId = scheduler.addEvent({
            //    start_date: "2014-11-19 09:00",
            //    end_date: "2014-11-19 12:00",
            //    text: "test"
            //});

            //scheduler.showLightbox(eventId);




            //var strid = "1261150564";
            // scheduler.showLightbox = function (id) {
            //   var ev = scheduler.getEvent(id);
            // ev.text = '22222222222222222222222';
            // };
            // scheduler.load("Data.json", "json");

            //scheduler.parse([
            //	{ start_date: "2014-11-19 09:00", end_date: "2014-11-19 12:00", text: "Task A-12458", section_id: 1, id: 1 },
            //	{ start_date: "2014-11-19 12:00", end_date: "2014-11-19 17:00", text: "Task A-46598", section_id: 1, id: 2 },

            //	{ start_date: "2014-11-19 09:00", end_date: "2014-11-19 11:00", text: "Task B-48865", section_id: 2, id: 3 },
            //	{ start_date: "2014-11-19 11:00", end_date: "2014-11-19 12:00", text: "Task B-44864", section_id: 2, id: 4 },
            //	{ start_date: "2014-11-19 13:30", end_date: "2014-11-19 18:00", text: "Task B-46558", section_id: 2, id: 5 },

            //	{ start_date: "2014-11-19 08:00", end_date: "2014-11-19 12:00", text: "Task C-32421", section_id: 3, id: 6 },
            //	{ start_date: "2014-11-19 14:30", end_date: "2014-11-19 16:45", text: "Task C-14244", section_id: 3, id: 7 },

            //	{ start_date: "2014-11-19 09:20", end_date: "2014-11-19 11:30", text: "Task D-52688", section_id: 4, id: 8 },
            //	{ start_date: "2014-11-19 16:00", end_date: "2014-11-19 18:00", text: "Task D-12458", section_id: 4, id: 9 }
            //], "json");
        }


    </script>
</head>
<body id="BodyGent" onload="init();">
    <div id="scheduler_here" class="dhx_cal_container" style='width: 100%; height: 100%;'>

        <div class="dhx_cal_navline">
            <%-- <button onclick="top.location='/frmCompletRoom.aspx'">Test</button>--%>
            <%-- <button onclick="topLocation('/frmCompletRoom.aspx')">Test</button>--%>
            <%--  <div class="dhx_cal_prev_button">&nbsp;</div>--%>
            <%--         <div class="dhx_cal_next_button">&nbsp;</div>--%>
            <%-- <div class="dhx_cal_today_button"></div>--%>
            <div class="dhx_cal_date"></div>
            <!--<div class="dhx_cal_tab" name="day_tab" style="right:204px;"></div>
        <div class="dhx_cal_tab" name="week_tab" style="right:140px;"></div>
        <div class="dhx_cal_tab" name="timeline_tab" style="right:280px;"></div>
        <div class="dhx_cal_tab" name="month_tab" style="right:76px;"></div>-->
            <%--         <div  id="btnSave" class="dhtmlx_button" style="right: auto; left: 50px; width:150px;height:35px;background-color:transparent">
               <input  class="dhtmlx_button" id="Button1" type="button" value="Confrim Booking" onclick="getValue();"  style="width:150px;height:35px;background-color:skyblue"  />

            </div>--%>

            <%--                           <input  class="dhtmlx_button" id="Button1" type="button" value="Close" onclick="getValue();"  style="width:75px;height:35px;background-color:brown"  />--%>
            <%--               &nbsp;
            <input class="dhtmlx_button" id="Button2" type="button" value="Clear" onclick="ReFeshPage();" style="width: 75px; height: 35px; background-color: GrayText" />
            &nbsp;
            <input class="dhtmlx_button" id="Button3" type="button" value="Confrim Booking" onclick="onConfirm();" style="width: 150px; height: 35px; background-color: skyblue" />--%>

            <br />
            <%--        <div class="dhx_btn_set dhx_left_btn_set dhx_save_btn_set"><div dhx_button="1" class="dhx_save_btn"></div><div>Save</div></div>--%>


            <input class="dhtmlx_button" id="btnBack" type="button" value="Back" style="width: 75px; height: 35px; background-color: gray" onclick="topLocation('/frmRequestRoom.aspx?RowIDMenu=20');" />
            <input class="dhtmlx_button" id="btnSave" type="button" value="Save" style="width: 75px; height: 35px; background-color: deepskyblue" onclick="onConfirm();" />
<%--            <input class="dhtmlx_button" id="btnClear" type="button" value="Clear" style="width: 75px; height: 35px; background-color: deepskyblue" onclick="topLocation('/frmCompletRoom.aspx?id=1');" />--%>





        </div>
        <div class="dhx_cal_header">
        </div>
        <div class="dhx_cal_data">
        </div>
    </div>
    <div id="MainContentDiv"></div>

    <%--   <form id="form1" runat="server">
        <asp:HiddenField ID="hPurpose" runat="server" />
        <asp:HiddenField ID="hBuilding" runat="server" />
        <asp:HiddenField ID="hUserid" runat="server" />
    </form>--%>
</body>
</html>
