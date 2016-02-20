// Room: /d/heimuya/house1.c
// Last Modified by winder on Apr. 10 2000
inherit ROOM;
void create()
{
	set("short","内室");
	set("long",@LONG
这是一个精雅的小舍，一进门便可闻到一阵浓冽的花香。房中挂着
一幅五女向凤图，图中绘着五个宫装美女，美目盼兮，艳丽脱俗。屋里
还有一张茶几，几张椅子，椅子上铺着绣花锦垫，西面有一扇洞形门通
向后厅。
LONG );

	set("exits",([
		"west"  : __DIR__"houting",
	]));
	set("no_clean_up", 0);
	set("coor/x", -3240);
	set("coor/y", 4210);
	set("coor/z", 100);
	setup();
	replace_program(ROOM);
}
