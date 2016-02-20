// Room: /d/yanping/yidao2.c
// Date: Sep 28, 2002  Winder

inherit ROOM;

void create()
{
	set("short", "闽浙驿道");
	set("long", @LONG
自古入闽无敞途。往来货运全靠肩挑背扛，逶迤入闽，车马不通。
古驿道沿建溪溪流南下，经此一个高坡逶迤而上，眼前林海如浪，远处
云雾笼罩，好一个风光所在。站在山顶隘口，远眺延平街市，双溪拱饶
直如棋盘一般。
LONG );
	set("exits", ([
		"northdown" : __DIR__"yidao1",
		"southup"   : __DIR__"gubao",
	]));
	set("no_clean_up", 0);
	set("outdoors", "yanping");
	set("coor/x", 1500);
	set("coor/y", -6100);
	set("coor/z", 30);
	setup();
	replace_program(ROOM);
}
