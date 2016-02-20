// Room: /d/5lt/guangbozhan.c

inherit  ROOM;

void  create  ()
{
	set  ("short",  "广播站");
	set  ("long",  @LONG
天气好热，蝉儿深藏在绿树中，叫得令人生厌。你踱着方步迈进了
广播站，发觉这儿简直就是另外一个世界，空中不时飘来阵阵优美的旋
律，让人耳目顿新。
LONG);
	set("exits",  ([  //sizeof()  ==  1
		"west"  :  __DIR__"nroad2",
	]));
	set("no_fight", 1);
	set("coor/x", -140);
	set("coor/y", 30);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
