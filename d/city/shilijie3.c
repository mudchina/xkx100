// Room: /yangzhou/shiliji3.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;

void create()
{
	set("short","十里长街");
	set("long",@LONG
这是一条宽阔的青石街道，向南北两头延伸。北边是北城门通向城
外。南边显得很繁忙。东边是一座两层的楼阁，挂着“太白遗风”的招
帘，门额上悬挂一方横匾，“醉仙楼”三字擦得闪闪发亮，乃是苏学士
的手笔。阵阵酒肉香让你垂涎欲滴。西边是一座样式古朴的庙宇，香火
缭绕，那就是天下学武之人所共同敬仰的武庙了。
LONG );
	set("outdoors", "yangzhouw");

	set("exits", ([
		"west"  : __DIR__"wumiao",
		"east"  : __DIR__"zuixianlou",
		"south" : __DIR__"shilijie4",
		"north" : __DIR__"shilijie2",
	]));
	set("objects", ([
		CLASS_D("yunlong")+"/ma" : 1,
	]));
	set("coor/x", 10);
	set("coor/y", 0);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
