// Room: /d/suzhou/shuiwa.c
// Last Modified by winder on Mar. 8 2001

#include <ansi.h>
inherit RIVER;

void create()
{
	::create();
	set("short", "划船坞");
	set("long", @long
这里名为“画船楼”，俗称“划船坞”，相传西施在此玩龙舟。向
南有一条直通太湖的人工开凿的小溪。从这坐船能够到达运河之上。
long);
	set("outdoors", "suzhou");
	set("exits",([
		"westup"    : __DIR__"shiyuan",
		"southwest" : __DIR__"caixiangjing",
	]));
	set("item_desc", ([
		"river" : "近岸处有一叶小舟，也许喊(yell)一声船家就能听见。\n",
	]));
	set("outdoors", "suzhou");
	set("coor/x", 930);
	set("coor/y", -1110);
	set("coor/z", 0);
  set("yell_about", "船家");             // yell 船家
  set("river_type", "湖");               // 江面上传来回响
  set("need_dodge",300);                 // 需要多少轻功
  set("come_msg_out",   "一叶扁舟缓缓地驶了过来，采莲女将一块踏脚板搭上堤岸，以便乘客上下。\n");
  set("busy_msg",       "只听得湖面上隐隐传来：“别急嘛，这儿正忙着呐……”\n");
  set("wait_msg",       "岸边一只渡船上的采莲女说道：正等着你呢，上来吧。\n");
  set("leave_msg_out",  "采莲女把踏脚板收了起来，竹篙一点，扁舟向湖边驶去。\n");
  set("leave_msg_in",   "采莲女把踏脚板收起来，说了一声“坐稳喽”，竹篙一点，扁舟向湖边驶去。\n");
  set("come_msg_in",    "采莲女说“到啦，上岸吧”，随即把一块踏脚板搭上堤岸。\n");
  set("item_desc/river", HIC "\n只见近岸处有一叶小舟，也许大声喊("
                         HIY "yell" HIC ")一声船家(" HIY "boat" HIC
                        ")就\n能听见。倘若你自负轻功绝佳,也可直接"
                        "渡水(" HIY "cross" HIC ")踏水而过。\n" NOR);
  set("boat_short", "渡船");    
  set("boat_desc",  @LONG
一叶小舟，最多也就能载七、八个人。一名十多岁的采莲小姑娘手
持长竹篙，正在船尾轻轻地荡舟。
LONG );
  set("to",         __DIR__"szyunhe");  // 船的终点 /*   必选   */
	setup();
}

