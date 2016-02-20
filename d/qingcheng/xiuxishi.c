// Room: /d/qingcheng/xiuxishi.c

inherit RESTROOM_IN;

void create()
{
	set("short", "厢房");
	set("long", @LONG
这是间整洁的厢房，明净透亮的窗户用厚厚的窗纱遮了大半，光线
很昏暗。房里别无他物，只有中间放着一张收拾得舒舒服服的大床，看
着就让人想睡觉。看来这里是青城休息的地方。
LONG );
	set("sleep_room", 1);
	set("no_fight", 1);
	set("no_clean_up", 0);
	set("coor/x", -8091);
	set("coor/y", -840);
	set("coor/z", 90);
  set("door_name","大门");
	set("door_dir","east");
	set("force_name","方人智");
  set("outroom",__DIR__"zoulang3");
  setup();
}
