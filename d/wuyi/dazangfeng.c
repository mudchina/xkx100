// Room: /d/wuyi/dazangfeng.c
// Last modified by Winder on Mar.20.2002

inherit ROOM;

void create()
{
	set("short", "大藏峰");
	set("long", @LONG
每次看到这座四曲南岸的大藏峰，总有一股透着玄机的冷意浸透你
的心田，让你顿感岁月在这里是这样的苍老和深邃，历史在这里有时如
此的厚重和迷茫。大藏峰在溪边横空崛起，陡峭千仞。半壁有两个洞穴，
上穴“金窠岩”中有千年不腐的稻草，下穴“金鸡洞”内有虹桥板和几
具船棺。所谓“千古浮名都是梦，百年人事尽如斯。”。
LONG );
	set("outdoors", "wuyi");
	set("no_clean_up", 0);
	set("exits", ([
		"northdown" : __DIR__"4qu",
	]));
	set("objects", ([
		"/d/taishan/npc/shu-sheng" : 1,
	]));
	set("coor/x", 1370);
	set("coor/y", -5020);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}

