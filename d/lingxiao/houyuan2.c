// Room: /d/lingxiao/houyuan2.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;
#include <ansi.h> 
void create()
{
	set("short","后园");
	set("long",@LONG 
这里重门叠户，是凌霄城上层人物的居所了。一般弟子要是没什么
事，是不能随便进来的。旁边几丛绿竹，郁郁葱葱。屋柱上尽皆雕镂着
雪花六出之形，一盆盆梅花栽种在屋廊之中。比起外面合围粗的各色梅
树，又是别有风情，左边是白万剑的家，右边是封万里的住所。
LONG);
	set("outdoors", "lingxiao");
	set("exits",([ /* sizeof() == 1 */
		"northwest" : __DIR__"zoulang3", 
		"northeast" : __DIR__"zoulang4", 
		"south"     : __DIR__"houyuan1",  
		"north"     : __DIR__"bridge", 
		"west"      : __DIR__"qihan", 
		"east"      : __DIR__"fenghuo", 
	]));
	set("objects", ([ 
	   __DIR__"obj/mei" : 2, 
	]));
	set("coor/x", -31000);
	set("coor/y", -8850);
	set("coor/z", 140);
	setup();
	replace_program(ROOM);
}
