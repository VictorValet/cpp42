#ifndef DATA_HPP
# define DATA_HPP

class Data
{
	public:
		Data(void);
		Data(int x);
		Data(const Data &original);
		Data	&operator=(const Data &original);
		~Data(void);
		int		getI(void) const;
		void	setI(int x);

	private:
		int	i;
};

#endif
