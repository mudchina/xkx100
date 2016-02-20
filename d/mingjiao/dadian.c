//room: /d/mingjiao/dadian.c
inherit ROOM;

void init();

void create()
{
	set("short","明教大殿");
	set("long", @LONG
走进这里，突感一阵肃穆之意，大殿中十分空旷，殿顶高悬八盏金
灯，两旁是精壮佩剑武士剑气森严逼人。正中设一宝座，前有一雕花檀
木案，案头供明教圣火令(ling)六枚。宝座后立有一扇玉屏，屏中所画
正是明教圣火图，烈焰直逼日月。宝座上端坐一人，着布衣而显高贵，
含笑不怒而自威，正是明教教主张无忌。
LONG );
	set("exits",([
	    "south" : __DIR__"qiandian",
	    "enter" : __DIR__"neishi",
	]));
	set_temp("tieling",8);
	set("objects",([
		CLASS_D("mingjiao")+"/zhangwuji":1,
		CLASS_D("mingjiao")+"/yangxiao":1,
		CLASS_D("mingjiao")+"/fanyao":1,
		CLASS_D("mingjiao")+"/yintianzheng":1,
		CLASS_D("mingjiao")+"/xiexun1":1,
		CLASS_D("mingjiao")+"/weiyixiao":1,
	]));
	set("coor/x", -52030);
	set("coor/y", 1070);
	set("coor/z", 110);
	setup();
}