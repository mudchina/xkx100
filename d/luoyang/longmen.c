//  Room:  /d/luoyang/longmen.c

inherit  ROOM;

void  create  ()
{
	set("short",  "龙门石窟");
	set("long",  @LONG
这里就是著名的龙门石窟，凡来洛阳游玩的游客比来此观摩。此处
的石窟造像，密布于两岸的崖壁上，长达两华里。它和敦煌莫高窟、大
同云岗石窟，合称我国三大石窟艺术宝库。此石窟开创于北魏孝文帝迁
都洛阳的公元四百九十三年前后，历经东、西魏、北齐、隋、唐、北宋
等七个朝代四百多年的大规模营造，使两边山窟密如蜂窝。有古阳洞、
宾阳洞、药方洞、潜溪寺、万佛洞、奉先寺等多处景点。东香山也是唐
诗人白居易晚年寓居地，琵琶峰下苍松翠柏中有白居易墓。
LONG);
	set("exits",  ([  /*  sizeof()  ==  2  */
		"eastup"    :  __DIR__"baiyuan",
		"westdown"  :  __DIR__"longmen1",
	]));
	set("outdoors", "luoyang");
	set("no_clean_up", 0);
	set("coor/x", -400);
	set("coor/y", -45);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
