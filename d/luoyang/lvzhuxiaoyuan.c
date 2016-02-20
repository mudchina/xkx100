//  Room:  /d/luoyang/lvzhuxiaoyuan.c

inherit  ROOM;

void  create  ()
{
	set("short",  "绿竹小院");
	set("long",  @LONG
这是一个绿竹遮蔽下的清凉小院，院子里有五间小舍，左二右三，
均以粗竹子架成。地上摆满了竹条、竹篾和一个快做好的竹篮子。一个
老翁正在院中劈柴升火做饭。象是感觉到你走进来了，可他连头也没给
抬一抬。
LONG);
	set("exits",  ([  /*  sizeof()  ==  2  */
		"south"      :  __DIR__"lvzhulin",
		"northwest"  :  __DIR__"zuoshe1",
		"northeast"  :  __DIR__"youshe1",
	]));
	set("objects",  ([
		CLASS_D("heimuya")+"/lvzhuweng" : 1,
		__DIR__"obj/zhudao" : 1,
	]));
	set("outdoors", "luoyang");
	set("coor/x", -380);
	set("coor/y", 30);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}