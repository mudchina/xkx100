// Room: /d/kunlun/nvwoshi.c
// Last Modified by winder on Nov. 15 2000

inherit ROOM;

void create()
{
	set("short","女弟子休息室");
	set("long",@LONG
这是间整洁的厢房，是昆仑派内女弟子们的休息室，因为门窗常闭
着，光线很昏暗。房里放着几张收拾得舒舒服服的木床，看着就让人想
睡觉。
LONG
);
	set("exits",([
		"northwest" : __DIR__"jiuqulang2",
	]) );
	set("no_clean_up",0);
	set("no_fight", 1);
	set("sleep_room", 1);
	set("coor/x", -119970);
	set("coor/y", 40080);
	set("coor/z", 90);
	setup();
	replace_program(ROOM);
}