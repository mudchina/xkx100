// /guanwai/laolongtou.c
inherit ROOM;

void create()
{
	set("short", "老龙头");
	set("long", @LONG
老龙头是万里长城最东端。澄海楼巍峨高踞城头上，楼上“雄襟万
里”的横匾居高临下，直俯大海。自澄海楼筑有一石城逐级而下伸入大
海，站在石城终端楼平台上四眺，海天一色，无边无际，气象万千。
LONG );
	set("exits", ([
		"northwest" : __DIR__"shanhaiguan",
		"southwest" : "/d/beijing/road3",
	]));
	set("objects",([
		__DIR__"npc/fengxifan" : 1,
	]));
//	set("no_clean_up", 0);
 	set("outdoors", "guanwai");
	set("coor/x", 5100);
	set("coor/y", 4500);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
