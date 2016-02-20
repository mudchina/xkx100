// Room: /d/lingxiao/walle3.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;
void create()
{
	set("short", "城头");
	set("long", @LONG
远山渺渺，冷风萧萧。试拂铁衣，只见衣色似雪，在这凌霄之处，
惟有雨雪连绵，以陪弋人。大漠苍苍，远空一鹰高翔，振翅直飞九霄，
忽而又直冲而下，翱翔九天，瞬间无踪，只有白云千载，仍在这座孤城
上悠悠飘荡。
LONG );
	set("outdoors", "lingxiao");
	set("exits", ([
		"west" : __DIR__"walle2",
	]));
	set("objects", ([
		__DIR__"npc/dizi" : 1,
	])); 
	set("coor/x", -30970);
	set("coor/y", -8930);
	set("coor/z", 150);
	setup();
	replace_program(ROOM);
}

