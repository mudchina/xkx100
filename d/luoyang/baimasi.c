// Room: /d/luoyang/baimasi.c
// Last modified by winder 2002.11.11

inherit  ROOM;

void  create  ()
{
	set("short",  "白马寺");
	set("long",  @LONG
这里就是著名的白马寺，从寺庙点燃的众多香火来看，这里一直很
旺盛，每天来此上香的香客络绎不绝。传东汉明帝刘庄夜梦金神，从西
而来，飞绕殿庭。于是，派十八人出使西域，拜求佛法，在大月氏遇天
竺高僧摄摩腾、竺法兰，得见佛经佛像。永平十年，汉使梵僧以白马驮
载佛经佛像返洛，翌年建寺，遂以白马为名。是佛教传入中原后官府营
建的第一座佛教寺院。后世奉此寺为中华佛教的“祖庭”和“释源”。
天王、大雄、接引、毗卢等殿建筑完整，居然躲过了多年的战乱。寺前
有一对石雕白马，栩栩如生。
LONG);
	set("exits",  ([  /*  sizeof()  ==  2  */
		"east"      :  __DIR__"baima1",
		"southwest" :  __DIR__"road2",
	]));
	set("outdoors", "luoyang");
	set("no_clean_up", 0);
	set("coor/x", -190);
	set("coor/y", 50);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
