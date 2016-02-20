// Room: /d/chengdu/dongjie2.c
// Last Modifyed by Winder on Jan. 4 2002

inherit ROOM;

void create()
{
	set("short", "东大街");
	set("long", @LONG
你刚走到这，就听到北边隐隐传来钟声，其中似乎还渗杂着“咚咚”
的木鱼之声。你顺着响声望去，但见眼前一座老高的寺门，门匾上三个
金光大字“昭觉寺”。你往南边看去，只见到一条小街。
LONG	);
	set("outdoors", "chengdu");
	set("exits", ([
		"west"  : __DIR__"dongjie1",
		"east"  : __DIR__"dongjie3",
		"north" : __DIR__"shimiao",
		"south" : __DIR__"xiaojie",
	]));
	set("objects", ([
		__DIR__"npc/seng-ren" : 1,
	]));
	set("coor/x", -8030);
	set("coor/y", -3000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

