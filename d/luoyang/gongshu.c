// Room: /d/luoyang/gongshu.c
// Last modified by winder 2002.11.11

inherit  ROOM;

void  create  ()
{
	set("short",  "贡书处");
	set("long",  @LONG
大禹治水时，一神龟从洛河爬出，背上数字排列为“戴九履一，左
三右七，二四为肩，六八为足，五居中央”。此为洛书。大禹依照洛书
制定出治理天下之九章大法。今洛宁洛河岸边西长水村旁，有“洛出书
处”古碑两通，据说为当年“神龟贡书”之处。河图洛书以天地之数奇
妙组合而涵盖天人合一思想之宇宙图式，反映出东方哲学思想之精髓。 
LONG);
	set("exits",  ([  /*  sizeof()  ==  2  */
		"west" : __DIR__"dukou1",
	]));
	set("outdoors", "luoyang");
	set("no_clean_up", 0);
	set("coor/x", -470);
	set("coor/y", -40);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
