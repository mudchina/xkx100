// Room: /d/nanshaolin/zhonglou.c
// Last Modified by Winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "钟楼小院");
	set("long", @LONG
这是一座砖木结构的宝塔，塔高七层，塔身作八角形，飞檐翘翎，
檐角上挂满了一串串小铜铃，随风叮叮作响。塔身墙上镂空雕绘着无数
佛陀们的坐像。一个个形态维肖，看来出自名匠之手。塔底入口处开了
一扇拱形的小木门，门扇两侧用彩漆涂绘，画的是释祖在灵山对诸天众
佛讲经时的情形。
LONG );

	set("exits", ([
		"west"  : __DIR__"celang-3",
		"enter" : __DIR__"zhlou1",
	]));
	set("objects",([
		__DIR__"npc/seng-bing3" : 2,
	]));
	set("outdoors", "nanshaolin");
	set("coor/x", 1840);
	set("coor/y", -6280);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
	if ( me->query("id") == "seng bing" &&  dir == "enter" ) return 0;
	return ::valid_leave(me, dir);
}

