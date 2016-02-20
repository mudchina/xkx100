// Room: /d/baituo/sheyuan.c
// Last Modified by winder on May. 15 2001
inherit ROOM;

void create()
{
	set("short","蛇园");
	set("long", @LONG
这里是白驼山庄的蛇园。白驼山以毒名扬天下，最重要的毒质就来
自毒蛇。这里遍地是蛇，墙上也巴着蛇，屋檐上也向下垂着蛇，树枝上
也盘绕着蛇，不由你不心惊。
LONG );
	set("exits",([
		"west"  : __DIR__"tuyuan",
	]));
	set("outdoors", "baituo");
	set("objects",([
		"/d/shenlong/npc/jinshe" :1,
		"/d/shenlong/npc/dushe" :1,
		"/d/shenlong/npc/fushe" :1,
		"/d/shenlong/npc/qingshe" :1,
		"/d/yanping/npc/wubushe" :1,
	]));
	set("coor/x", -49990);
	set("coor/y", 20080);
	set("coor/z", 30);
	setup();
	replace_program(ROOM);
}
