// Room: /d/nanshaolin/chanfang-3.c
// Last Modified by Winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "禅房");
	set("long", @LONG
这里是诵经的禅房。房中有一座小香炉，淡淡的清烟从中散出，弥
漫在整间房内。阳光透过窗格照在青石地上，在青烟中形成根根耀眼的
光柱。屋中的地上散放着几个蒲团，几个年青的僧人正闭目打坐于其上。
LONG );
	set("exits", ([
		"north" : __DIR__"chanfang-1",
	]));
	set("objects",([
		"/d/shaolin/obj/fojing2"+random(2) : 1
	]));
	set("no_fight", 1);
	set("coor/x", 1790);
	set("coor/y", -6280);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
