// Room: /d/changcheng/shanhaiguan.c
// Last Modified by Winder on Aug. 25 2000
#include <ansi.h>

inherit ROOM;
string look_gaoshi();

void create()
{
	set("short", "山海关城楼");
	set("long", WHT@LONG
你登上山海关城楼，北望巍峨的角山，长城在山脊上奔腾，渐渐消
失在黛色的群山之中。关下，沉沉一线穿南北；南面，烟波万顷，横无
际涯。大明元帅徐达以此处“枕山襟海，实辽蓟咽喉”，故筑此关。
LONG
NOR  );
	set("outdoors", "changcheng");
	set("exits", ([
		"northwest" :__DIR__"changcheng23",
		"down"      :"/d/guanwai/shanhaiguan",
	]));
	set("no_clean_up", 0);
	set("coor/x", 5000);
	set("coor/y", 5000);
	set("coor/z", 80);
	setup();
	replace_program(ROOM);
}