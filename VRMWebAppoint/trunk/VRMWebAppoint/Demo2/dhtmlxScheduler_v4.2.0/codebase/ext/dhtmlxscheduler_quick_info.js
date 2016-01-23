/*
dhtmlxScheduler v.4.2.0 Stardard

This software is covered by GPL license. You also can obtain Commercial or Enterprise license to use it in non-GPL project - please contact sales@dhtmlx.com. Usage without proper license is prohibited.

(c) Dinamenta, UAB.
*/
scheduler.config.icons_select=["icon_details","icon_delete"],scheduler.config.details_on_create=!0,scheduler.config.show_quick_info=!0,scheduler.xy.menu_width=0,scheduler.attachEvent("onClick",function(e){return scheduler.showQuickInfo(e),!0}),function(){for(var e=["onEmptyClick","onViewChange","onLightbox","onBeforeEventDelete","onBeforeDrag"],t=function(){return scheduler._hideQuickInfo(),!0},s=0;s<e.length;s++)scheduler.attachEvent(e[s],t)}(),scheduler.templates.quick_info_title=function(e,t,s){return s.text.substr(0,50)
},scheduler.templates.quick_info_content=function(e,t,s){return s.details||s.text},scheduler.templates.quick_info_date=function(e,t,s){return scheduler.isOneDayEvent(s)?scheduler.templates.day_date(e,t,s)+" "+scheduler.templates.event_header(e,t,s):scheduler.templates.week_date(e,t,s)},scheduler.showQuickInfo=function(e){if(e!=this._quick_info_box_id&&this.config.show_quick_info){this.hideQuickInfo(!0);var t=this._get_event_counter_part(e);t&&(this._quick_info_box=this._init_quick_info(t),this._fill_quick_data(e),this._show_quick_info(t))
}},scheduler._hideQuickInfo=function(){scheduler.hideQuickInfo()},scheduler.hideQuickInfo=function(e){var t=this._quick_info_box;if(this._quick_info_box_id=0,t&&t.parentNode){var s=t._offsetWidth;if(scheduler.config.quick_info_detached)return t.parentNode.removeChild(t);"auto"==t.style.right?t.style.left=-s+"px":t.style.right=-s+"px",e&&t.parentNode.removeChild(t)}},dhtmlxEvent(window,"keydown",function(e){27==e.keyCode&&scheduler.hideQuickInfo()}),scheduler._show_quick_info=function(e){var t=scheduler._quick_info_box;
scheduler._obj.appendChild(t);var s=t.offsetWidth,r=t.offsetHeight;scheduler.config.quick_info_detached?(t.style.left=e.left-e.dx*(s-e.width)+"px",t.style.top=e.top-(e.dy?r:-e.height)+"px"):(t.style.top=this.xy.scale_height+this.xy.nav_height+20+"px",1==e.dx?(t.style.right="auto",t.style.left=-s+"px",setTimeout(function(){t.style.left="-10px"},1)):(t.style.left="auto",t.style.right=-s+"px",setTimeout(function(){t.style.right="-10px"},1)),t.className=t.className.replace("dhx_qi_left","").replace("dhx_qi_right","")+" dhx_qi_"+(1==e?"left":"right"))
},scheduler.attachEvent("onTemplatesReady",function(){if(scheduler.hideQuickInfo(),this._quick_info_box){var e=this._quick_info_box;e.parentNode&&e.parentNode.removeChild(e),this._quick_info_box=null}}),scheduler._quick_info_onscroll_handler=function(){scheduler.hideQuickInfo()},scheduler._init_quick_info=function(){if(!this._quick_info_box){var e=scheduler.xy,t=this._quick_info_box=document.createElement("div");t.className="dhx_cal_quick_info",scheduler.$testmode&&(t.className+=" dhx_no_animate");
var s='<div class="dhx_cal_qi_title" style="height:'+e.quick_info_title+'px"><div class="dhx_cal_qi_tcontent"></div><div  class="dhx_cal_qi_tdate"></div></div><div class="dhx_cal_qi_content"></div>';s+='<div class="dhx_cal_qi_controls" style="height:'+e.quick_info_buttons+'px">';for(var r=scheduler.config.icons_select,a=0;a<r.length;a++)s+='<div class="dhx_qi_big_icon '+r[a]+'" title="'+scheduler.locale.labels[r[a]]+"\"><div class='dhx_menu_icon "+r[a]+"'></div><div>"+scheduler.locale.labels[r[a]]+"</div></div>";
s+="</div>",t.innerHTML=s,dhtmlxEvent(t,"click",function(e){e=e||event,scheduler._qi_button_click(e.target||e.srcElement)}),scheduler.config.quick_info_detached&&(scheduler._detachDomEvent(scheduler._els.dhx_cal_data[0],"scroll",scheduler._quick_info_onscroll_handler),dhtmlxEvent(scheduler._els.dhx_cal_data[0],"scroll",scheduler._quick_info_onscroll_handler))}return this._quick_info_box},scheduler._qi_button_click=function(e){var t=scheduler._quick_info_box;if(e&&e!=t){var s=e.className;if(-1!=s.indexOf("_icon")){var r=scheduler._quick_info_box_id;
scheduler._click.buttons[s.split(" ")[1].replace("icon_","")](r)}else scheduler._qi_button_click(e.parentNode)}},scheduler._get_event_counter_part=function(e){for(var t=scheduler.getRenderedEvent(e),s=0,r=0,a=t;a&&a!=scheduler._obj;)s+=a.offsetLeft,r+=a.offsetTop-a.scrollTop,a=a.offsetParent;if(a){var i=s+t.offsetWidth/2>scheduler._x/2?1:0,n=r+t.offsetHeight/2>scheduler._y/2?1:0;return{left:s,top:r,dx:i,dy:n,width:t.offsetWidth,height:t.offsetHeight}}return 0},scheduler._fill_quick_data=function(e){var t=scheduler.getEvent(e),s=scheduler._quick_info_box;
scheduler._quick_info_box_id=e;var r=s.firstChild.firstChild;r.innerHTML=scheduler.templates.quick_info_title(t.start_date,t.end_date,t);var a=r.nextSibling;a.innerHTML=scheduler.templates.quick_info_date(t.start_date,t.end_date,t);var i=s.firstChild.nextSibling;i.innerHTML=scheduler.templates.quick_info_content(t.start_date,t.end_date,t)};
//# sourceMappingURL=../sources/ext/dhtmlxscheduler_quick_info.js.map