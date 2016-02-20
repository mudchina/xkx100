// Room: /d/qilian/bonanshan.c
// Winder 2000/09/05 

inherit ROOM;

void create()
{
	set("short", "博南山");
	set("long", @LONG
往北走，地面已渐渐地不再平坦，由丘陵地区转入山区。大路到此
就中断了，只剩坎坷不平的山路。再往北就是祁连山。东面是通向兰州
官道。
LONG );
	set("outdoors", "qilian");
	set("no_clean_up", 0);
	set("exits", ([
		"eastdown" : "/d/xingxiu/xxroad2",
		"north"    : __DIR__"bulangpo1",
	]));
	set("coor/x", -9900);
	set("coor/y", 2700);
	set("coor/z", 60);
	setup();
	replace_program(ROOM);
}