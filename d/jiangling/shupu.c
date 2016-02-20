//Edited by fandog, 01/31/2000

inherit ROOM;

void create ()
{
	set ("short", "书铺");
	set ("long", @LONG
这是荆州城里的一家书铺，平时生意颇为冷清，最近却来了不少江
湖豪客，嚷嚷着要买《唐诗选辑》，即便提价到五两银子一本，也争先
恐后地掏钱，惟恐买迟了就没有了。店里的伙计在忙着招呼客人，眉开
眼笑地收钱找钱。几个身上带刀带剑、挺胸凸肚的练把式爷们在粗声大
气地讨论着什么，时而停下来急急翻动手里的书，似乎那书里有什么天
大的秘密。
LONG);
	set("exits", ([ 
		"east" : __DIR__"xijie3",
	]));
	set("objects", ([
		"/d/huashan/npc/haoke"  : 2,
		"/d/taishan/npc/jian-ke": 1,
		"/d/taishan/npc/dao-ke" : 1,
	]));

	set("coor/x", -1510);
	set("coor/y", -2030);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
