// Room: xiuxishi.c

inherit RESTROOM_IN;

void create()
{
        set("short", "桃花轩");
        set("long", @LONG
这是间整洁的厢房，因门窗常闭着，光线很昏暗。房里别无他物，
只有中间放着一张收拾得舒舒服服的大床，看着就让人想睡觉。
LONG );
        set("sleep_room", 1);
        set("no_fight", 1);
        set("no_clean_up", 0);
        set("coor/x", 8970);
	set("coor/y", -2990);
	set("coor/z", 0);
  set("door_name","门");
	set("door_dir","east");
	set("force_name","梅超风");
  set("outroom",__DIR__"siguoshi");
	setup();
}
