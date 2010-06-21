int lkl_br_add_bridge(const char* bridge_name)
{
	int ret;
#ifdef SIOCBRADDBR
	ret = lkl_sys_ioctl(bridge_socket(), SIOCBRADDBR, (unsigned long) bridge_name);
	if (ret < 0) {
#endif
		char br_name[IFNAMSIZ];
		unsigned long arg[3] = {
			BRCTL_ADD_BRIDGE,
			(unsigned long) br_name
		};

		strncpy(br_name, bridge_name, IFNAMSIZ);
		ret = lkl_sys_ioctl(bridge_socket(), SIOCSIFBR, (unsigned long) arg);
	}

	return ret;
}
