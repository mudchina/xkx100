// Room: /d/huanggong/shenwumen.c

inherit ROOM;

void create()
{
	set("short", "神武门");
	set("long", @LONG
原称玄武门. 这里是皇城的北门, 呈凹字形的建筑, 与午门合称两
阙, 是防御和保卫皇城的宫门. 门楼重檐庑殿顶, 内设钟鼓, 黄昏时鸣
钟百零八响, 而后起更击鼓报时, 直到次日拂晓鸣钟. 每年遴选秀女, 
应选女子皆从此门入宫. 明末李自成攻进北京城时, 崇祯帝由此门逃上
煤山, 自缢身亡. 
LONG 	);
	set("outdoors", "huanggong");
	set("no_fight", "1");
	set("exits", ([ /* sizeof() == 2 */
		"east"  : __DIR__"dao5",
		"west"  : __DIR__"dao6",
		"north" : __DIR__"jingshan",
		"south" : __DIR__"qinandian",
	]));
	set("objects", ([
		__DIR__"npc/yulin" : 2,
		__DIR__"npc/chaerzhu" : 1,
	]));

	set("coor/x", -200);
	set("coor/y", 5260);
	set("coor/z", 0);
	setup();
}

int valid_leave(object me, string dir)
{
	if (dir!="north")
		return notify_fail("察尔珠上前挡住你，朗声说道：这位"+RANK_D->query_respect(me)+"，入宫走前门。\n");
	return ::valid_leave(me, dir);
}