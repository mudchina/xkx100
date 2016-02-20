// /kaifeng/guandi.c
// Last modified by winder 2003.10.20

inherit ROOM;

void create()
{
	set("short", "关帝庙");
	set("long", @LONG
关帝庙前一个老大的铁香炉，因为关老爷忠义守信。所以商人们订
了协议总要拜一下关帝爷。许多希望能在武举中得胜的人，也都要到这
庙来烧香。毕竟关帝又被称为武圣。
LONG);
	set("objects", ([
		__DIR__"npc/obj/guanyu" : 1,
	]));
	set("exits", ([
		"west" : __DIR__"paifang",
	]));
	setup();
	replace_program(ROOM);
}
