// Room: /d/kunlun/shufang.c
// Last Modified by Winder on Nov. 15 2000

inherit ROOM;

void create()
{
	set("short", "书房");
	set("long", @LONG
这里是书房，靠墙一排大书架，摆放着很多的书籍，昆仑三圣何足
道以琴棋而号称以“圣”，故昆仑派一直引以为荣，鼓励弟子学琴棋艺。
一眼望过去，似乎有关于不少琴棋方面的书。
LONG );
	set("exits", ([
		"west"  : __DIR__"jiuqulang3",
	]));
	set("no_clean_up", 0);
	set("coor/x", -119970);
	set("coor/y", 40100);
	set("coor/z", 90);
	setup();
	replace_program(ROOM);
}