//Edited by fandog, 01/31/2000

inherit ROOM;

void create ()
{
	set ("short", "古隆中");
	set ("long", @LONG
这是一个小村庄，但见四周群山环抱，松柏参天，溪流萦绕，景色
秀丽。相传诸葛亮幼年失去双亲，十七岁上随叔父诸葛玄来到这里隐居，
躬耕苦读。
LONG);
	set("outdoors", "jiangling");
	set("exits", ([
		"west" : __DIR__"shennongjia",
		"south": __DIR__"shandao3",
	]));
  
	set("coor/x", -1510);
	set("coor/y", -2040);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}