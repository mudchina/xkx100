// d/qingcheng/chufang.c
//
inherit ROOM;

void create()
{
	set("short", "厨房");
	set("long", @LONG
这是青城山的厨房，收拾得异常干净。中央摆着大圆桌，桌上摆着
一些点心和茶水，周围则放着几张竹椅。窗口还摆着几盆山野鲜花。平
时青城山的弟子和家眷都在这里用餐。
LONG );
	set("exits",([
		"south" :__DIR__"zoulang3",
	]));
	set("objects",([
		__DIR__"obj/laitangyuan" : random(3)+1,
		__DIR__"obj/kudingcha" : random(2)+1,
	]));

	set("no_clean_up", 0);
	set("coor/x", -8090);
	set("coor/y", -830);
	set("coor/z", 90);
	setup();
	replace_program(ROOM) ;
}