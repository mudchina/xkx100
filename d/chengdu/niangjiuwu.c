// Room: /d/chengdu/niangjiuwu.c
// Last Modifyed by Winder on Jan. 4 2002

inherit ROOM;

void create()
{
	set("short", "酿酒屋");
	set("long", @LONG
你来到一座老式的房子中间。在你的左手面有一个很大很大的木桶，
约有二人多高。在木桶的上面，站着几个精赤着上身的大汉，手里拿着
竹竿在奋力的朝木桶搅动着。正前方站着一个半老的徐娘，在和几个小
伙子眉来眼去地说笑着。
LONG	);
	set("exits", ([
		"northwest" : __DIR__"xiaojie2",
	]));
	set("objects", ([
		__DIR__"npc/wangerniang" : 1,
		__DIR__"npc/xiaohuozi" : 3,
	]));
	set("coor/x", -8000);
	set("coor/y", -3040);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

