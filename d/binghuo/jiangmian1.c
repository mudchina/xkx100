// Room: /binghuo/jiangmian1.c
// Date: Oct.28 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "钱塘江面");
	set("long", @LONG
只听得雷声隐隐，钱塘江上夜潮已至。潮声如雷，震耳欲聋，江
船猛地被抛了起来。说话声尽皆掩没。向窗外看时，只见巨浪犹如一
堵透明的高墙，两岸风物被掩没在惊涛之中了。
LONG );
	set("no_sleep_room",1);
	set("outdoors", "wangpan");
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

