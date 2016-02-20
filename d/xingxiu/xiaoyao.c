// Xiaoyao.c:  the sleeping room for Xingxiu
// Last Modified by winder on Feb. 28 2001

inherit ROOM;

void create()
{
	set("short", "逍遥洞");
	set("long", @LONG
这里就是星宿弟子淫乐之处。原来不过是一粗糙的石洞，后因众星
宿弟子不断修缮，成了方园几百里臭名昭著的淫窟。不知有多少牧羊女
在此暗无天日，度过余生。
    洞里面铺了几张臭烘烘的草垫子。垫子旁边是一些破酒罐子。洞壁
(wall)上有些字迹。
LONG );
	set_light(0);
	set("sleep_room", "1");
	set("no_fight", "1");
	set("exits", ([
		"out" : __DIR__"shidao",
	]));
	set("item_desc", ([
		"wall" : "星宿淫贼人人得而诛之！\n\n         哇！爽死了！\n",
	]) );
	set("no_clean_up", 0);
	set("coor/x", -50200);
	set("coor/y", 20220);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
