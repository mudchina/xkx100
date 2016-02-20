// Room: /d/kunlun/jingshenfeng.c 惊神峰
// Last Modified by winder on Nov. 14 2000

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short","惊神峰"NOR);
	set("long",@long
折而向北，过了一岭，只见古柏三把百余章，皆挺直端秀，凌霄托
根树旁，作花柏顶，灿若云荼。走出十余丈，只听得琴声之中杂有无数
鸟语，细细听来，琴声竟似和鸟语互相应答，间间关关，宛转啼鸣。只
见三株大松树下一个白衣男子背向而坐，膝上放着一张焦尾琴，整自弹
奏。他身周树木上停满了鸟雀，黄莺，杜鹃，喜鹊，八哥，还有许多不
知其名的，和琴声或一问一答，或齐声和唱。
long );
	set("objects",([
		CLASS_D("kunlun")+"/hezudao" : 1,
	]));
	set("exits", ([
		"south" : __DIR__"sanshengao",
	]));
	set("outdoors", "kunlun");
	set("coor/x", -119980);
	set("coor/y", 40180);
	set("coor/z", 100);
	setup();
	replace_program(ROOM);
}