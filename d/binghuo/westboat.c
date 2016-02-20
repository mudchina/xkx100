// Room: /binghuo/westboat.c
// Date: Oct.28 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "钱塘江面");
	set("long", @LONG
只听得雷声隐隐，钱塘江上夜潮已至。潮声如雷，震耳欲聋，大
船猛地被抛了起来。说话声尽皆掩没。大船顺风顺水，向杭州疾驰。
LONG );
	set("no_sleep_room",1);
	set("outdoors", "wangpan");
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

