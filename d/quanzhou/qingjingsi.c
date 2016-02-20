// Room: /d/quanzhou/qingjingsi.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "清净寺");
	set("long", @LONG
这是一座依照叙利亚大马士革伊斯兰礼拜堂而建的教堂，全部用青
色和白色的花岗石建造。高大的穹形顶的尖拱大门使人们站在门内，大
有「天作穹庐地作毡」之感。寺内还有一「永乐上谕」石刻。寺门后的
西侧是「奉天坛」，阿拉伯教徒在此面西朝拜。
    门楣上还刻有「可兰经」。
LONG );
	set("exits", ([
		"south" : __DIR__"tumenji",
		"north" : __DIR__"alabo",
	]));
	set("objects", ([
		__DIR__"npc/huihui" : 1,
	]));
	set("coor/x", 1860);
	set("coor/y", -6570);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
