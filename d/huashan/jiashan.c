// jiashan.c
// Last Modified by winder on Aug. 1 2002

inherit ROOM;
void create()
{
	set("short","假山小池");
	set("long",@LONG
这是另一个小园子，里头有个小池塘。四周布有假山，增添林园美
景。下雨时雨水落入溪塘中，清脆的水珠声有如玉珠落盘般悦耳。水气
朦胧中抬头西望，只见远处苍山如黛，若隐若现，雨景妙趣无穷。
LONG);
	set("exits",([
		"east" : __DIR__"houyuan",
	]));
	set("objects", ([
		"/clone/medicine/vegetable/shengdi" : random(2),
	]));
	set("outdoors", "huashan");
	set("coor/x", -890);
	set("coor/y", 210);
	set("coor/z", 120);
	setup();
	replace_program(ROOM);
}
 
