// Room: xiuxishi.c 休息室
// By Marz

inherit RESTROOM_IN;

void create()
{
        set("short", "休息室");
        set("long", @LONG
这是间整洁的厢房，因门窗常闭着，光线很昏暗。房里别无他物，
只有中间放着一张收拾得舒舒服服的大床，看着就让人想睡觉。
LONG );
        set("no_clean_up", 0);
        set("sleep_room", 1);
        set("no_fight", 1);
        set("coor/x", -2030);
	set("coor/y", -910);
	set("coor/z", 90);
  set("door_name","门");
	set("door_dir","south");
	set("force_name","张松溪");
  set("outroom",__DIR__"donglang2");
	setup();
}
