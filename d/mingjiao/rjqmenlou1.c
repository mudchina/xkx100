//RJQMENLOU1.C

inherit ROOM;

void create()
{
	set("short", "门楼一层");
	set("long", @LONG
这里是一间大石室，石室四周整齐的码置着兵器架，十八般兵器样
样俱全。几个教众在室中巡逻，好象是守护兵器的。右面有一条石梯直
通楼上。
LONG );
	set("exits", ([
		"up" : __DIR__"rjqmenlou2",
		"east" : __DIR__"rjqyuan",
	]));
	set("no_clean_up", 0);
	set("coor/x", -52030);
	set("coor/y", 860);
	set("coor/z", 50);
	setup();
	replace_program(ROOM);
}