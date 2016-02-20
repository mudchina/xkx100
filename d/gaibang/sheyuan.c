//room: sheyuan.c
inherit ROOM;

void create()
{
	set("short","蛇园");
	set("long", @LONG
这里是丐帮弟子的蛇园。丐帮弟子生活俭朴，随地坐卧，不免常
受蛇虫侵犯。日久天长，渐渐摸索出驯养之道。这里遍地是蛇，墙上
也巴着蛇，屋檐上也向下垂着蛇，树枝上也盘绕着蛇，不由你不心惊。
LONG );
	set("exits",([
		"west"  : __DIR__"pomiao",
	]));
	set("outdoors", "yangzhoue");
	set("objects",([
		"/d/shenlong/npc/jinshe" :1,
		"/d/shenlong/npc/dushe" :1,
		"/d/shenlong/npc/fushe" :1,
		"/d/shenlong/npc/qingshe" :1,
		"/d/yanping/npc/wubushe" :1,
	]));
	set("coor/x", 80);
	set("coor/y", 60);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
