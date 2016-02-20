// Room: /d/suzhou/huzhongdao.c
// Last Modified by winder on Mar. 8 2001

#include <ansi.h>
inherit RIVER;

void create()
{
	::create();
	set("short", "湖中岛");
	set("long",@long
这里是太湖中心的一个小岛，小岛的中心有一座亭子。
long);
	set("outdoors","suzhou");
	set("exits",([
		"north" : __DIR__"bishuiting",
	]));
	set("no_clean_up", 0);
	set("coor/x", 800);
	set("coor/y", -1205);
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
  set("to",         __DIR__"road5");  // 船的终点 /*   必选   */
	setup();
}

