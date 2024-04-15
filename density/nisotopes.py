from mendeleev import element

def print_isotope_counts():
    # Iterate through elements from Hydrogen to Einsteinium
    for symbol in range(1, 100):
        try:
            elem = element(symbol)
            isotopes = elem.isotopes
            if isotopes:
                num_isotopes = len(isotopes)
                print(f" {num_isotopes}")
            else:
                print(f"{elem.symbol}: No known isotopes.")
        except ValueError:
            # Skip if the element doesn't exist
            pass

if __name__ == "__main__":
    print_isotope_counts()
