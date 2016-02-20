// Room: /d/kunlun/bayankala.c
// Last Modified by winder on Nov. 14 2000

#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
	set("short", "巴颜喀拉山");
	set("long",@long
这巴颜喀拉山山势低平，西接昆仑山垭口，又与通天河支流德曲相
隔，沼泽遍布。在山脚放眼望去，随处可见一处处沼泽草甸，乃是放牧
各类牲畜的好地方。远处散布着一顶顶牧民的蒙古包。
long);
	set("exits",([
		"west"      : __DIR__"kekexili",
		"southdown" : __DIR__"shanlu2",
		"northwest" : __DIR__"hmszroad1",
	]));

	set("objects",([
		__DIR__"obj/da-shitou.c" :  1,
	]));

	set("outdoors", "kunlun");
	set("coor/x", -90000);
	set("coor/y", 10000);
	set("coor/z", 30);
	setup();
	replace_program(ROOM);
}
