// Room: /yangzhou/yinxie.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;

void create()
{
	set("short","春草池塘");
	set("long",@LONG
春草池塘吟榭面东三楹。榭内悬姚元三题匾，外柱悬挂魏之祯所书
集杜牧、韦庄诗句楹联(lian)。
LONG );
	set("outdoors", "shouxihu");
	set("item_desc", ([
		"lian" : "
        碧        绿
        落        波
        青        春
        山        浪
        飘        满
        古        前
        韵        陂
\n",
	]));
	set("exits", ([
		"east" : __DIR__"taohuawu",
	]));
	set("no_clean_up", 0);
	set("coor/x", -1);
	set("coor/y", 40);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}